#include "node.h"
// #include<stdio.h>

int get_gno(int id){
	int multiplier = 1;
	int num = id;
	int gno = 0;
	for(int i=0;i<4;i++){
		gno += (num%10)*multiplier;
		num/=10;
		multiplier*=10;
	}
	return gno;
}

int get_mno(int id){
	int multiplier = 1;
	int num = id/10000;
	int mno = 0;
	for(int i=0;i<3;i++){
		mno += (num%10)*multiplier;
		num /= 10;
		multiplier *= 10;
	}
	return mno;
}

BOOL IsLower_GM(int id1, int id2)
{
	// printf("%d , %d\n",get_gno(id1),get_mno(id1));
	// printf("%d , %d\n",get_gno(id2),get_mno(id2));

	int g1 = get_gno(id1);
	int g2 = get_gno(id2);

	int m1 = get_mno(id1);
	int m2 = get_mno(id2);

	if(g1 < g2){
		return TRUE;
	}
	else if(g2 < g1){
		return FALSE;
	}
	else{
		//when group numbers are equal, check by member numbers
		if(m1 < m2)
			return TRUE;
		else
			return FALSE;
	}

}
