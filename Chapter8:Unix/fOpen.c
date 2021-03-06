#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
  int charsleft;
  char *nextCharPos;
  char *baseBuff;
  int flag;
  int fd;
} FILE;

enum _flags {
  _READ = 01,
  _WRITE = 02,
  _UNBUF = 04,
  _EOF = 010,
  _ERR = 020
};

FILE _iob[OPEN_MAX] = {
  { 0, (char *) 0, (char *) 0, _READ, 0},
  { 0, (char *) 0, (char *) 0, _WRITE, 1},
  { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 },
};

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

int _fillbuff(FILE *);
int _flushbuff(int, FILE *);

#define feof(p) ((p) -> flag & _EOF) != 0)
#define ferror(p) ((p) -> flag & _ERR) != 0)
#define fileno(p) ((p) -> fd)

#define getc(p) (--(p)->charsleft >= 0 ? (unsigned char) *(p) -> nextCharPos++ : _fillbuf(p))
#define putc(x, p) (--(p)->charsleft >= 0 ? *(p) -> nextCharPos++ = (x) : _flushbuf((x), p))


#include <fcntl.h>
#include "syscall.h"
#include <stdlib.h>
#include <unistd.h>

#define PERMS 0666

FILE *fopen(char *name, char *mode) {
  int fd;
  FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  
  for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    if ((fp -> flag & (_READ | _WRITE)) == 0)
      break;
    
  if (fp >=_iob + OPEN_MAX)
      return NULL;
  
  if (*mode == 'w')
    fd = creat(name, PERMS);

  else if (*mode == 'a'){
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  }
  else 
    fd = open(name, O_RDONLY, 0);
  
  if (fd == -1)
    return NULL;
  
  fp -> fd = fd;
  fp -> charsleft = 0;
  fp -> baseBuff = NULL;
  fp -> flag = (*mode == 'r') ? _READ : _WRITE;

  return fp;
}

int _fillbuf(FILE *fp){
  int bufsize;

  if ((fp ->flag & (_READ|_EOF)) != _READ)
    return EOF;
  
  bufsize = (fp -> flag & _UNBUF) ? 1 : BUFSIZ;
  if (fp -> baseBuff == NULL)
    if ((fp -> baseBuff = (char *) malloc(bufsize)) == NULL)
      return EOF;
  
  fp -> nextCharPos = fp -> baseBuff;
  fp -> charsleft = read(fp -> fd, fp -> nextCharPos, bufsize);

  if (--fp -> charsleft < 0){
    if (fp -> charsleft == -1)
      fp -> flag = _EOF;
    else
      fp -> flag |= _ERR;
    
    fp -> charsleft = 0;
    return EOF;
    }

    return (unsigned char) *fp -> nextCharPos++;
}

int _flushbuf(int c, FILE *fp) {
  int bufsize, char_written;
  unsigned char uc = c;
  
  if ((fp -> flag) & (_WRITE|_EOF|_ERR) != _WRITE)
    return EOF;
  
  if (fp -> baseBuff == NULL && ((fp -> flag & _UNBUF) == 0)){
     if ((fp -> baseBuff = malloc(BUFSIZ)) == NULL)
      fp -> flag |= _UNBUF;
    else {
      fp -> nextCharPos = fp -> baseBuff;
      fp -> charsleft = BUFSIZ - 1;
    }
  }

  if (fp -> flag & _UNBUF) {
    fp -> nextCharPos = fp -> baseBuff = NULL;
    fp -> charsleft = 0;
    if (c == EOF)
      return EOF;

    char_written = write(fp -> fd, &uc, 1);
    bufsize = 1;
  } 
  else {
    bufsize = (int)(fp -> nextCharPos - fp -> baseBuff);
    char_written = write(fp -> fd, fp -> baseBuff, bufsize);
    fp -> nextCharPos = fp -> baseBuff;
    fp -> charsleft = BUFSIZ - 1;
  }
 
  if (char_written == bufsize)
    return c;
  else{
    fp -> flag |= _ERR;
    return EOF;
  }
  
}


int main() {

  char alo;

  alo = getc(stdin);
  putc(alo, stdout);

  

  return 0;
}