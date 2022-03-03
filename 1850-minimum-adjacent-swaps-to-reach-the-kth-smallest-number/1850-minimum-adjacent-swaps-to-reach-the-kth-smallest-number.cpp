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