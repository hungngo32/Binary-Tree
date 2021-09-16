#include "tree.h"
void khoiTaoCay(TREE &p) {
	p = NULL;
}
void themNode(TREE &p, int x) {
	if (p == NULL) {
		NODE* t = new NODE;
		t->data = x;
		t->pLeft = NULL;
		t->pRight = NULL;
		p = t;
	}
	else {
		if (x > p->data) {
			themNode(p->pRight, x);
		}
		 if (x< p->data)
		{
			themNode(p->pLeft, x);
		}
	}
}
void inDanhSach(TREE p) {
	if (p != NULL) {
		cout << p->data << " ";
		inDanhSach(p->pLeft);
		inDanhSach(p->pRight);
	} 
}
void Menu(TREE& p) {
	int luachon;
	khoiTaoCay(p);
	system("cls");
	while (true)
	{


		cout << "\n\n\t\t======MENU======";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Xuat du lieu";
		cout << "\n0.Ket thuc";
		cout << "\n\n\t\t======END======";
		cout << "\nNhap lua chon cua ban: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			int x;
			cout << "\nNhap x: ";
			cin >> x;
			themNode(p, x);
			system("pause");
			break;
		case 2:
			inDanhSach(p);
			system("pause");
			break;
		default:
			break;
		}
	}
}