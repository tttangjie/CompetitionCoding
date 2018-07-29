#include <errno.h>
#include <string.h>
#include <sys/mount.h>
#include "tst_test.h"

#define MNTPOINT  "mntpoint"

static char long_path[PATH_MAX + 2];
static int mount_flag;
static int fd;

static struct tcase {
        const char *err_desc;
        const char *mntpoint;
        int exp_errno;
} tcases[] = {
        {"Already mounted/busy", MNTPOINT, EBUSY},
        {"Invalid address", NULL, EFAULT},
        {"Directory not found", "nonexistent", ENOENT},
        {"Invalid  device", "./", EINVAL},
        {"Pathname too long", long_path, ENAMETOOLONG}
};

static void verify_umount(unsigned int n)
{
        struct tcase *tc = &tcases[n];

        TEST(umount(tc->mntpoint));

        if (TEST_RETURN != -1) {
                tst_res(TFAIL, "umount() succeeds unexpectedly");
                return;
        }

        if (tc->exp_errno != TEST_ERRNO) {
                tst_res(TFAIL | TTERRNO, "umount() should fail with %s",
                        tst_strerrno(tc->exp_errno));
                return;
        }

        tst_res(TPASS | TTERRNO, "umount() fails as expected: %s",
                tc->err_desc);
}

static void setup(void)
{
        memset(long_path, 'a', PATH_MAX + 1);

        SAFE_MKFS(tst_device->dev, tst_device->fs_type, NULL, NULL);
        SAFE_MKDIR(MNTPOINT, 0775);
        SAFE_MOUNT(tst_device->dev, MNTPOINT, tst_device->fs_type, 0, NULL);
        mount_flag = 1;

        fd = SAFE_CREAT(MNTPOINT "/file", 0777);
}

static void cleanup(void)
{
        if (fd > 0 && close(fd))
                tst_res(TWARN | TERRNO, "Failed to close file");

        if (mount_flag)
                tst_umount(MNTPOINT);
}

static struct tst_test test = {
        .tid = "umount02",
        .tcnt = ARRAY_SIZE(tcases),
        .needs_root = 1,
        .needs_tmpdir = 1,
        .needs_device = 1,
        .setup = setup,
        .cleanup = cleanup,
        .test = verify_umount,
};
