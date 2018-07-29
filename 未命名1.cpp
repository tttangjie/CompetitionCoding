int main(int argc,char*argv[]) {
	if(argc<2) {
		printf("no usr name input");
		return 1;
	}
	if(geteuid()!=0)
		fprintf(stderr,"mustbesetuidroot");
	struct passwd*pwd;
	pwd=getpwnam(argv[1]);
	if(pwd==NULL)
		printf("no user name found.\n");
	else {
		printf("passwd:%s\n",pwd->pw_passwd);
		if(strcmp(pwd->pw_passwd,"x")==0) {
			printf("shadowused.\n");
			struct spwd *shd=getspnam(argv[1]);
			if(shd!=NULL) {
				static char crypt_char[80];
				strcpy(crypt_char,shd->sp_pwdp);
				char salt[13];
				int i=0,j=0;
				while(shd->sp_pwdp[i]!='\0') {
					salt[i]=shd->sp_pwdp[i];
					if(salt[i]=='$') {
						j++;
						if(j==3) {
							salt[i+1]='\0';
							break;
						}
					}
					i++;
				}
				if(j<3)perror("fileerrororusercannotuse.");
				if(argc==3)
					printf("salt:%s,crypt:%s\n",salt,crypt(argv[2],salt));
				printf("shadowdpasswd:%s\n",shd->sp_pwdp);
			}
		}
	}
	return 0;
}

