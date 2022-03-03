Firstly, we find the next kth permutation using next_permutation which is an inbuilt function .
Then , we think greedily and try to put every digit to its correct position and count the swaps needed for each and place the digit in front and similarly traverse for the rest of the digits.

e.g. we have num=1234 , k=5
then the required number will be 1432
then after first iteration it will remain the same as 1==1
on 2!=4 we will count 2 swaps and put 4 in its correct position then num becomes 1423.. similarly we will do for the upcoming digits.

class Solution {
public:
int getMinSwaps(string num, int k) {
string a=num;
int c=0;
while(k--)
{
next_permutation(num.begin(),num.end()); //finding next kth permutation
}
int j;
for(int i=0;i<a.length();i++)
{
if(a[i]!=num[i])
{
for( j=i+1;j<a.length();j++)
{
c++; // counting how much ahead the current digit is from its required position
if(num[i]==a[j])
{
break;
}
}
char t=a[j];
for(int k=j-1;k>=i;k--)
{
a[k+1]=a[k]; //placing the digit to its correct position
}
a[i]=t;
}
}
return c;
}
};
