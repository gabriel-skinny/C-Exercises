#include <stdio.h>
#include <string.h>
#include "syscall.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"
#include <stdlib.h>

#define NAME_MAX_M 14

typedef struct {
  long ino;
  char name[NAME_MAX_M+1];
} Dirent;

typedef struct {
  int fd;
  Dirent d;
} DIRM;

DIRM *opendirM(char *dirname);
Dirent *readdirM(DIRM *dfd);
void closedirM(DIRM *dfd);

void fsize(char*);

int main(int argc, char *argv[]) {

  if (argc == 1)
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);

  return 0;
}

void dirwalk(char *, void (*fcn)(char*));

void fsize(char *name) {
  struct stat stbuf;

  if (stat(name, &stbuf) == -1){
    fprintf(stderr, "fsize: cant acess %s\n", name);
    return;
  }

  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  
  printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *)) {
  char name[MAX_PATH];
  Dirent *dp;
  DIRM *dfd;

  if ((dfd = opendirM(dir)) == NULL) {
    fprintf(stderr, "dirwalk: cant open %s\n", dir);
    return;
  }

  while ((dp = readdirM(dfd)) != NULL) {
    if (strcmp(dp -> name, ".") == 0 || strcmp(dp -> name, ".."))
      continue;
    
    if (strlen(dir) + strlen(dp -> name) + 2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp -> name);
    else{
      sprintf(name, "%s/%s", dir, dp -> name);
      (*fcn)(name);
    }
  }

  closedirM(dfd);
}


#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {
  ino_t d_ino;
  char d_name[DIRSIZ];
};

DIRM *opendirM(char *dirname) {
  int fd;
  struct stat stbuf;
  DIRM *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1
    || fstat(fd, &stbuf) == -1
    || (stbuf.st_mode & S_IFMT) != S_IFDIR
    || (dp = (DIRM *) malloc(sizeof(DIRM))) == NULL
  )
    return NULL;
  
  dp -> fd = fd;

  return dp;
}

void closedirM(DIRM *dp) {
  if (dp){
    close(dp -> fd);
    free(dp);
  }
}

#include <sys/dir.h>
#include <unistd.h>

Dirent *readdirM(DIRM *dp) {
  struct direct dirbuf;
  static Dirent d;

  while (read(dp -> fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)){
    if (dirbuf.d_ino == 0)
      continue;
    
    d.ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZ);
    d.name[DIRSIZ] = '\0';
    return &d;
  }

  return NULL;
}