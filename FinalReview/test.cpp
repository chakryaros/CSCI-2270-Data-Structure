#include<iostream>

using namespace std;

int SIZE = 5;

int hashtb(int key)
{
	return key%SIZE;
}
// int findProduct(TreeNode * root)
// {
//     	if(root != NULL)
//         {
//            return findProduct(root->left)* root->key  * findProduct(root->right);
//         }
//         else
//            return 1;
// }
int main()
{
	int array[5]= {10, 3, 20, 12, 30};
	int sum =0;
	int linear =0;
	// for(int i=0; i<5; i++)
	// {
	// 	sum=hashtb(array[i]);
	// 	//linear = (array[i]+ i)%SIZE;
	// 	cout<<sum<<" ";
	// }

	sum =41%10;
	// sum = 13%20;
	cout<<sum<<endl;

	
	return 0;
}