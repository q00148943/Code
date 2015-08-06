//
//  test.cpp
//
//  Created by q00148943 on 6/6/15.
//  Copyright (c) 2015 q00148943. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include <stack>

using namespace std;

const unsigned int MAX_INPUT_STR_LEN = 100;

int char_remove(char *str)
{
	if (str == NULL) {
		return 0;
	}

	unsigned int length = strlen(str);
	if (length > MAX_INPUT_STR_LEN) {
		return 0;
	}

	char c;
	stack<char> cstack;
	
	unsigned int i;
	for (i = 0; i < length; i++) {
		c = *(str + i);
		if ((c >= 'A') && (c <= 'Z')) {
			if (!cstack.empty()) {
				if (c == cstack.top()) {
					cstack.pop();
				}
				else {
					cstack.push(c);
				}
			}
			else {
				cstack.push(c);
			}
		}
	}

	return (cstack.empty()) ? 1 : 0;
}

int main(int argc, char *argv[])
{
	char s[] = "$#$%#%B&*(&*&*^&*^*^*A$%^&*(A)*)(*)*(*B*&&&*&*CDEFGGFEDC(&(*&%&%^*(&(&&*(&*";
	printf("%d\n", char_remove(s));
	
    return 0;
}

