#include "tree.h"
void khoiTaoCay(TREE &p) {
	p = NULL;
}
bool Prime(int n) {
	if (n <= 1) return false;
	if (n == 2 || n == 3) return true;
	for (int i = 2; i*i <=n; i++) {
		if (n % i == 0) return false;
	}
	return true;
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
		else if (x< p->data)
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
void DuyetLNR(TREE p) {
	if (p != NULL) {
		DuyetLNR(p->pLeft);
		cout << p->data<<" ";
		DuyetLNR(p->pRight);
	}
}
void DuyetLRN(TREE p) {
	if (p != NULL) {
		DuyetLRN(p->pLeft);
		DuyetLRN(p->pRight);
		cout << p->data << " ";
	}
}
void inNguyenTo(TREE p) {
	if (p != NULL) {
		if (Prime(p->data)) {
			cout << p->data << " ";
		}
		inDanhSach(p->pLeft);
		inDanhSach(p->pRight);
	}
}
pair<int,int> timMaxMin(pair<int,int> a,TREE p) {
	if (p != NULL) {
		if (p->data < a.first) a.first = p->data;
		if (p->data > a.second) a.second = p->data;
		a=timMaxMin(a, p->pLeft);
		a=timMaxMin(a, p->pRight);
	}
	return a;
}
void Menu(TREE& p) {
	int luachon;
	pair <int, int> t;
	t.first = 100;
	t.second = -100;
	khoiTaoCay(p);
	system("cls");
	while (true)
	{


		cout << "\n\n\t\t======MENU======";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Xuat du lieu";
		cout << "\n3.NLR";
		cout << "\n4.LNR";
		cout << "\n5.LRN";
		cout << "\n6.In nguyen to";
		cout << "\n7.Tim min max";
		cout << "\n8. Node co 2 la";
		cout << "\n9.Node co 1 la";
		cout << "\n0.Ket thuc";
		cout << "\n\n\t\t======END======";
		cout << "\nNhap lua chon cua ban: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			int x, n;
			cout << "\nNhap so luong: ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "\nNhap x: ";
				cin >> x;
				themNode(p, x);
			}
			system("pause");
			break;
		case 2:
			inDanhSach(p);
			system("pause");
			break;
		case 3:
			inDanhSach(p);
			system("pause");
			break;
		case 4:
			DuyetLNR(p);
			system("pause");
			break;
		case 5:
			DuyetLRN(p);
			system("pause");
			break;
		case 6:
			cout << "\nCac so nguyen to: ";
			inNguyenTo(p);
			system("pause");
			break;
		case 7:
		{
		t=timMaxMin(t, p);
		cout << t.first << " " << t.second;
		system("pause");
		break; }
		default:
			break;
			
		}
		system("pause");
		system("cls");
	}
}