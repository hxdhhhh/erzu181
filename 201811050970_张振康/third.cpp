#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Stu {
	int id;
	int chinese;
	int math;
	int english;
	int sum;
}stu[305];
bool cmp(struct Stu a, struct Stu b) {
	if(a.sum != b.sum) {
		return a.sum > b.sum;
	} else {
		if(a.chinese != b.chinese) {
			return a.chinese > b.chinese;
		} else {
			return a.id < b.id;
		}
	}
}
int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		stu[i].id = i+1;
		scanf("%d %d %d", &stu[i].chinese, &stu[i].math, &stu[i].english);
		stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
	}
	sort(stu, stu+n, cmp);
	for(i = 0; i < 5; ++i) {
		printf("%d %d\n", stu[i].id, stu[i].sum);
	}
	return 0;
}

