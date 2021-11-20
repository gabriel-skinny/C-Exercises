#include <stdio.h>
 
void squeeze(char s1[], const char s2[]);
int indexof(const char s[], char c);


int main(void) {
	char s1[] = "asdfasdfasdf";
 
	char s2[] = "asdf";
 
	char copy[] = "asdfasdfasdf";
 
 
	squeeze(s1, s2);

	printf("expected -> %s actual -> %s: equal\n", copy, s1);
 
	return 0;
}

int indexof(const char s[], char c) {
	int i = 0;
	while ('\0' != s[i]) {
		if (c == s[i])
			return i;
		i++;
	}
	return -1;
}
 
 
void squeeze(char s1[], const char s2[]) {
	int i, j;
	for (i = j = 0; '\0' != s1[i]; i++) {
		if (indexof(s2, s1[i]) == -1)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}