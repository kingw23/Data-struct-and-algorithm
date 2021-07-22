#include <string>
#include <iostream>
using namespace std;

typedef int DataType;

class Node
{
public:
	DataType data;
	Node* next;
};

class LinkList
{
public:
	LinkList();
	~LinkList();
	int CreateLinkList(int size);
	int BYELinkList();
	int TravalLinkList();
	int InsertLinklList(Node* data, int n);
	int DeleteLinklist(int n);

	int GetLen();
	bool IsEmply();

	Node* head;
	int size;
};

LinkList::LinkList()
{
	head = new Node; // �����ַ
	head->data = 0;
	head->next = NULL;// ��ʼ��ͷָ��
	size = 0;
}

LinkList::~LinkList()
{
	delete head;
}

int LinkList::CreateLinkList(int n)
{
	if (n < 0) {
		printf("error\n");
		return -1;
	}
	Node* ptemp = NULL;  // ��ǰָ��ָ��
	Node* pnew = NULL;

	this->size = n;
	ptemp = this->head;
	for (int i = 0; i < n; i++)
	{
		pnew = new Node;
		pnew->next = NULL;
		cout << "�����" << i + 1 << "���ڵ�ֵ" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;
		ptemp = pnew;
	}
	cout << "�������" << endl;
	return 0;
}

int LinkList::BYELinkList()
{
	Node* ptemp;
	if (this->head == NULL) {
		cout << "����ԭ����Ϊ��" << endl;
		return -1;
	}
	while (this->head)
	{
		ptemp = head->next;
		free(head);
		head = ptemp;
	}
	cout << "�����������" << endl;
	return 0;
}

int LinkList::TravalLinkList()
{
	Node* ptemp = this->head->next;
	if (this->head == NULL) {
		cout << "����Ϊ��" << endl;
		return -1;
	}
	while (ptemp)
	{
		cout << ptemp->data << "->";
		ptemp = ptemp->next;
	}
	cout << "NULL" << endl;
	return 0;
}

int LinkList::InsertLinklList(Node* data, int n)
{
	Node* ptemp;
	if (this->head == NULL) {
		cout << "����Ϊ��" << endl;
		return -1;
	}
	if (data == NULL) {
		cout << "����ڵ�Ϊ��" << endl;
		return -1;
	}
	//ͷ��
	if (n < 2) {
		Node* pnew = new Node;
		pnew->data = data->data;
		pnew->next = this->head->next;
		this->head->next = pnew;
		this->size++;
		return 0;
	}
	//β��
	if (n > this->size) {
		ptemp = this->head;
		while (ptemp->next != NULL) {
			ptemp = ptemp->next;
		}
		Node* pnew = new Node;
		pnew->data = data->data;
		pnew->next = NULL;
		ptemp->next = pnew;
		this->size++;
		return 0;
	}
	//�м��
	else {
		ptemp = this->head;
		for (int i = 1; i < n; i++) {
			ptemp = ptemp->next;
		}
		Node* pnew = new Node;
		pnew->data = data->data;
		pnew->next = ptemp->next;
		ptemp->next = pnew;
		this->size++;
		return 0;
	}
}

int LinkList::DeleteLinklist(int n)
{
	Node* ptemp;
	Node* ptemp2;
	if (n > this->size) {
		cout << "n̫��" << endl;
		return -1;
	}
	// ɾͷ�ڵ�
	if (n < 2) {
		ptemp = this->head->next;
		this->head->next = ptemp->next;
		free(ptemp);
		this->size--;
		return 0;
	}
	// β��ɾ��
	if (n == this->size) {
		ptemp = this->head;
		for (int i = 1; i < this->size; i++) {
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = NULL;
		free(ptemp2);
		this->size--;
		return 0;
	}
	// �м�ɾ��
	else
	{
		ptemp = this->head;
		for (int i = 1; i < n; i++) {
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = ptemp2->next;
		free(ptemp2);
		this->size--;
		return 0;
	}
}

int LinkList::GetLen()
{
	return this->size;
}

bool LinkList::IsEmply()
{
	if (this->head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void main(void)
{
	LinkList list;
	LinkList* plist = &list;
	plist->CreateLinkList(5);
	plist->TravalLinkList();
	Node temp;
	temp.data = 100;
	temp.next = NULL;
	plist->InsertLinklList(&temp, 0);
	plist->TravalLinkList();
	plist->InsertLinklList(&temp, plist->GetLen() + 1);
	plist->TravalLinkList();
	plist->InsertLinklList(&temp, 5);

	plist->TravalLinkList();
	plist->DeleteLinklist(0);
	plist->TravalLinkList();
	plist->DeleteLinklist(list.GetLen());
	plist->TravalLinkList();
	plist->DeleteLinklist(2);
	plist->TravalLinkList();


	plist->BYELinkList();
	system("pause");
}

