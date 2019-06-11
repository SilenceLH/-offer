// 剑指offer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "string"
#include "vector"
#include "stack"
using namespace std;


struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL){
	}
};
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
/************************************************************************/
/*                                   1、二维数组中的查找
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/
/************************************************************************/
	bool Find(int tager, vector<vector<int>> array) 
	{
		bool res = false;
		int len1 = array.size();
		int len2 = array[0].size();
		for (int i = 0; i  < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (array[i][j] == tager)
				{
					res = true;
				}
			}
		}
		return res;
	}
	bool Find1(int tager, vector<vector<int>> array)
	{
		int rowCount = array.size();
		int colCount = array[0].size();
		int i = rowCount - 1, j = 0;
		while (i >= 0 && j < colCount)
		{
			if (tager < array[i][j])
			{
				i--;
			}
			else if (tager > array[i][j])
			{
				j++;
			}
			else
				return true;
		}
		return false;
	}
	/************************************************************************/
	/*                                2、替换空格                     
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
	则经过替换之后的字符串为We%20Are%20Happy。
	*/
	/************************************************************************/
	void replaceSpace(char* str, int length) {
		if (str == nullptr || length == 0)
			return;
		int strlength = 0;
		int blacklength = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			strlength++;
			if (str[i] == ' ')
				blacklength++;
		}
		int newlength = strlength + blacklength * 2;
		while (blacklength >= 0 && newlength > strlength)
		{
			if (str[strlength] == ' ')
			{
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';
			}
			else
			{
				str[newlength--] = str[strlength];
			}
			strlength--;
		}
	}
	/************************************************************************/
	/*                      3、从尾到头打印链表
	输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。   
	*/
	/************************************************************************/
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		stack<int> s;
		ListNode* p = head;
		if (head == nullptr)
		{
			return res;
		}
		while (p != NULL)
		{
			s.push(p->val);
			p = p->next;
		}
		while (!s.empty()) 
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}
	/************************************************************************/
	/*										4、重建二叉树    
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
	则重建二叉树并返回。
	*/
	/************************************************************************/
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int len = pre.size();
		if (len == 0)
		{
			return NULL;
		}
		TreeNode* head = new TreeNode(pre[0]);
		vector<int> left_pre, right_pre, left_vin, right_vin;
		int gen = 0;
		for (int i = 0; i < len; i++)
		{
			if (vin[i] == pre[0])
			{
				gen = i;
				break;
			}
		}
		for (int i = 0; i < gen; i++)
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]); 
		}
		for (int i = gen + 1; i < len; i++)
		{
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;
	}
	/************************************************************************/
	/*                          5、用两个栈实现队列
	用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
	*/
	/************************************************************************/
		void push(int node) {
			stack1.push(node);
		}
		int pop() {
			if (stack2.empty())
			{
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
			int res = stack2.top();
			stack2.pop();
			return res;
		}
private:
	stack<int> stack1;
	stack<int> stack2;
	/************************************************************************/
	/*                           6、旋转数组的最小数字
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
	输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
	例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
	NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
	*/
	/************************************************************************/
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len == 0)
		{
			return 0;
		}
		int vin = rotateArray[0];
		for (int i = 1; i < len; i++)
		{
			if (rotateArray[i] < vin)
			{
				vin = rotateArray[i];
			}
		}
		return vin;
	}



};



int main()
{
    cout << "Hello World!\n"; 
	cout << "asdfa";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
