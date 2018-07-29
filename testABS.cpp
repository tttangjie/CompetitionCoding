#include "tst_test.h"

static struct tcase{
	const unsigned int before;
	const unsigned int after;
}tcases[]{
	{-3,3},
	{6,6},
	{0,0}
	{100000,100000}
}

static void verify_abs(unsigned int n){
	struct tcase *tc=&tcases[n];
	TEST(abs(tc->before)==tc->after);
	if(TEST_RETURN==1){
		tst_res(TPASS , "abs() succeeds unexpectedly");
		return ;
	}
	tst_res(TFSIL,"abs() should failed");
}

static struct tst_test test = {
	.tid = "test",
	.tcnt = ARRAY_SIZE(tcases),
	.needs_root = 1,
	.needs_tmpdir = 1,
	.format_device = 1,
	.test = test,
};
