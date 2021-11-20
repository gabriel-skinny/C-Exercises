#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main() {

  int pdayemonth[2];

  printf("\nDay of year 2021 is %d \n\n", day_of_year(2021, 3, 0));

  month_day(2020, 52, &pdayemonth[0], &pdayemonth[1]);

  printf("\nMonth of day 59 is month: %d and day: %d \n\n", pdayemonth[0], pdayemonth[1]);

  return 0;
}

static char month1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char month2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


static char *daytab[] = {month1, month2};



int day_of_year(int year, int month, int day) {
  int leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  char *initialPoint = daytab[leap];

  if (month <= 13 && month >= 0) {
    while((++daytab[leap] - initialPoint) < month)
      day+= *(daytab[leap]);

    return day;
  }

  return -1;
}

void month_day(int year, int yearday, int *pmoth, int *pday) {
  int leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  char *initialPoint = daytab[leap];

  while(yearday >= 0 && yearday > *(++daytab[leap]))    
      yearday-= *(daytab[leap]);
  
  if (daytab[leap] - initialPoint <= 12 && yearday >= 0){
    *pmoth = daytab[leap] - initialPoint - 1;
    *pday = yearday;
  }
  else {
    *pmoth = -1;
    *pday = -1;
  }
}