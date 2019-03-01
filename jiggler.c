//c file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//default values
#define D_JVER 	4
const char* D_DNAM = "Puzzle";
const char* D_DESC = "Created with NickJiggler";
const char* D_IURL = "https://github.com/RooMan-GBM";
const char* D_PURL = "https://github.com/RooMan-GBM";
const char* D_PKID = "Blue";

char *pkid; // package name eg. Cats,Dogs,Unicorns
char *pknm; // puzzle name eg. Keyboard Cat, Doge, Rainbow Unicorn
char *opfn; // output file name

int fileSize;
int jver=4;
int size1;
char tmp;
int main(int argc, char **argv){
 FILE *fp; //input file
 FILE *of; //output file
 if (argc<2){printf("error\n");return 1;}
// strcpy(pknm,argv[1]);
 //strcat(pknm,".jig");
 opfn=malloc(strlen(argv[1]));
 sprintf(opfn,"%s.jig",argv[1]);
 of=fopen(opfn,"wb");

 fputs("JIGC",of);
 putw(0,of);

 fputs("JVER",of);
 putw(sizeof(int),of);
 putw(4,of);

 fputs("DNAM",of);
 putw(strlen(argv[1]),of);
 fputs(argv[1],of);
 
 fputs("DESC",of);
 putw(strlen(D_DESC),of);
 fputs(D_DESC,of);

 fputs("IURL",of);
 putw(strlen(D_IURL),of);
 fputs(D_IURL,of); 

 fputs("PURL",of);
 putw(strlen(D_PURL),of);
 fputs(D_PURL,of); 

 fputs("PKID",of);
 putw(strlen(D_PKID),of);
 fputs(D_PKID,of); 

 fputs("PKNM",of);
 putw(strlen(D_PKID),of);
 fputs(D_PKID,of);

 fputs("TRIL\0",of);
 putw(1024,of);
 putc('\0',of);


 fputs("THMB",of);
 fp=fopen("THMB.jpeg","rb");
 fseek(fp,0,SEEK_END);
 size1=ftell(fp);
 putw(size1,of);
 rewind(fp);
 for (int i=0;i<size1;i++){
  putc( getc(fp),of);
}
fclose(fp);

 fputs("PIMG",of);
 fp=fopen("PIMG.jpeg","rb");
 fseek(fp,0,SEEK_END);
 size1=ftell(fp);
 putw(size1,of);
 rewind(fp);
 for (int i=0;i<size1;i++){
  putc( getc(fp),of);
}
fclose(fp);
fseek(of,0,SEEK_END);
size1=ftell(of);
fseek(of,4,SEEK_SET);
putw(size1,of);
 fclose(of);
 
  

 return 1;
}
