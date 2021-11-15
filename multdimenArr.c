#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main() {

  int pdayemonth[2];

  printf("\nDay of year 2021 is %d \n\n", day_of_year(2021, 0, 0));

  month_day(2020, 0, &pdayemonth[0], &pdayemonth[1]);

  printf("\nMonth of day 59 is month: %d and day: %d \n\n", pdayemonth[0], pdayemonth[1]);

  return 0;
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (month <= 13 && month >= 0) {
    for (i = 1; month <= 13 && i < month; i++)
      day+= daytab[leap][i];

    return day;
  }

  return -1;
}

void month_day(int year, int yearday, int *pmoth, int *pday) {
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;


  for (i = 1; yearday >= 0 && yearday > daytab[leap][i]; i++)     
      yearday-= daytab[leap][i];
  
  if (i <= 12 && yearday >= 0){
    *pmoth = i;
    *pday = yearday;
  }
  else {
    *pmoth = -1;
    *pday = -1;
  }
}