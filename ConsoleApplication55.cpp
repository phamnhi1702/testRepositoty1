#include <iostream>
#include <string>
using namespace std;

struct book
{
	string id,
		name,
		kind;
	book* next;
};

class bookshief
{
	book* head;
	book* tail;
public:
	bookshief();
	~bookshief();
	void add_first(book add);
	void add_prepos(book* x, book add);
	void add_nextpos(book* x, book add);
	void add_last(book add);
	book* search_book(string ma);
	void replace_book(book* b_old);
	void erase_first();
	void erase(book* object);
	void erase_last();
	void permute(book* a, book* b);
	void sort_name();
	void show();
};

bookshief::bookshief()
{
	book* head = NULL;
	book* tail = NULL;
}

bookshief::~bookshief() {}

book create_book()
{
	book b;
	string ma, ten, loai;
	cout << "Nhap ma: "; cin >> ma;
	cout << "Nhap ten: "; cin >> ten;
	cout << "Nhap loai: "; cin >> loai;
	b.next = NULL;
	b.id = ma;
	b.name = ten;
	b.kind = loai;
	return b;
}

void bookshief::add_first(book add)
{
	book* plus = new book();
	plus->id = add.id;
	plus->name = add.name;
	plus->kind = add.kind;
	plus->next = add.next;
	plus->next = head;
	head = plus;
}

void bookshief::add_prepos(book* x, book add)// add the second, the old second become the third
{
	book* plus = new book();
	plus->id = add.id;
	plus->name = add.name;
	plus->kind = add.kind;
	plus->next = add.next;
	for (book* i = head; i != NULL; i = i->next)
	{
		if (i->next == x)
		{
			cout << "\nDa tim thay i->next = x" << i->next << endl;
			plus->next = i->next;
			i->next = plus;
			return;
		}
	}
}

void bookshief::add_nextpos(book* x, book add)
{
	book* plus = new book();
	plus->id = add.id;
	plus->name = add.name;
	plus->kind = add.kind;
	plus->next = add.next;
	for (book* i = head; i != NULL; i = i->next)
	{
		if (i == x)
		{
			cout << "\nDa tim thay i = x" << i << endl;
			plus->next = i->next;
			i->next = plus;
			if (i == tail)  // if add after tail, it's become tail
				tail = plus;
			return;
		}
	}
}

void bookshief::add_last(book add)
{
	book* plus = new book();
	book* p = head;
	plus->id = add.id;
	plus->name = add.name;
	plus->kind = add.kind;
	plus->next = NULL;
	if (head == NULL)
		head = plus;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = plus;
		tail = plus;
	}
}

book* bookshief::search_book(string ma)
{
	for (book* i = head; i != NULL; i = i->next)
	{
		if (i->id == ma)
			return i;
	}
	return NULL;
}

void bookshief::replace_book(book* b_old)
{
	string ma, ten, loai;
	cout << "Nhap ma: "; cin >> ma;
	cout << "Nhap ten: "; cin >> ten;
	cout << "Nhap loai: "; cin >> loai;
	b_old->id = ma;
	b_old->name = ten;
	b_old->kind = loai;
	b_old->next = b_old->next;
}

void bookshief::erase_first()
{
	book* temp;
	temp = head;
	head = head->next;
	delete(temp);
}

void bookshief::erase(book* object)
{
	book* temp = object->next;
	object->next = temp->next;
	delete(temp);
}

void bookshief::erase_last()
{
	for (book* i = head; i != NULL; i = i->next)
	{
		if (i->next->next == tail)
		{
			tail = i;
			tail->next = NULL;
			delete(i->next);
			return;
		}
	}
}

void bookshief::permute(book* a, book* b)
{
	book* temp = new book();
	temp->id = a->id;
	temp->name = a->name;
	temp->kind = a->kind;

	a->id = b->id;
	a->name = b->name;
	a->kind = b->kind;

	b->id = temp->id;
	b->name = temp->name;
	b->kind = temp->kind;
}

void bookshief::sort_name()
{
	book* temp = new book();
	for (book* i = head; i != NULL; i = i->next)
	{
		for (book* j = i->next; j != NULL; j = j->next)
		{
			if (j->name < i->name)
			{
				permute(i, j);
			}
		}
	}
}

void bookshief::show()
{
	cout << "Ma sach \t Ten sach \t Loai sach" << endl;
	for (book* i = head; i != NULL; i = i->next)
	{
		cout << "\nhead: " << head->id << "\t" << head->name << "\t" << head->kind << endl;
		cout << i->id << " \t " << i->name << " \t " << i->kind << "\t" << i << endl;
		cout << "tail: " << tail->id << "\t" << tail->name << "\t" << tail->kind << endl;
	}
}

int dem;
bookshief bs;

void Init()
{
	int n;
	cout << "Nhap so luong sach: "; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		book b = create_book();
		bs.add_last(b);
	}

}

int main()
{
	Init();
	bs.show();
	/*string x;
	cout << "Nhap ma sach muon tim: "; cin >> x;
	book* address = bs.search_book(x);
	cout << "address: " << address << endl;
	bs.replace_book(address);
	bs.erase_last();
	book b = create_book();
	bs.add_nextpos(address, b);*/
	/*string x, y;
	cout << "Nhap ma hai sach muon doi cho: "; cin >> x >> y;
	bs.permute(bs.search_book(x), bs.search_book(y));*/
	bs.sort_name();
	bs.show();
}