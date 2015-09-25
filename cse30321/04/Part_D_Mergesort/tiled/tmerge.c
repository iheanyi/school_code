// adapted from:	http://www.cosc.canterbury.ac.nz/tad.takaoka/cosc229/imerge.c
// This is an iterative version of merge sort.
// It merges pairs of two consecutive lists one after another.
// After scanning the whole array to do the above job,
// it goes to the next stage. Variable k controls the size
// of lists to be merged. k doubles each time the main loop
// is executed.
#include <stdio.h>
#include <math.h>
int i, n, t, k, q;
int a[10000000], b[10000000];

int merge(int l, int r, int u) {
	int i, j, k;
	i = l;
	j = r;
	k = l;
	while (i < r && j < u) { 
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
		} 
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < r) { 
		b[k] = a[i];
		i++;
		k++;
	}
	while (j < u) { 
		b[k] = a[j];
		j++;
		k++;
	}
	for (k = l; k < u; k++) { 
		a[k] = b[k]; 
	}
}

/*
void sort(void) {
	int k, u;
	k = 1;
	while (k < n) {
		i = 1;
		while (i + k <= n) {
			u = i + k * 2;
			if (u > n)
				u = n + 1;
			merge(i, i + k, u);
			for (q = 1; q <= n; q++)
				printf("%d ", a[q]);
			printf("\n");
			i = i + k * 2;
		}
		k = k * 2;
	}
}
 */

void sort(int left, int right) {
	if (right - left == 1)
		return;
	int mid = (left + right) / 2;
	sort(left, mid);
	sort(mid, right);
	merge(left, mid, right);
}

int main(void) {
    n = 100;
    for (i=1;i<=n;i++) a[i]=n-i;
    sort(0,n);
}
