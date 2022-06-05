//nama:afriza tri rizki
//kelas:informatika-b
//SDA QUEUE-cilcular
#include <iostream>

using namespace std;

class queue {
	public:
		int arr[5], head = 0, tail = 0;

		//pengecheckan jika head dan tail menunjuk indexyang sama maka queuenya kosong
		bool empty() {
			if (tail == head) {
				return true;
			} return false;
		}

		//jika head menunjuk ke index sebelum tail maka queuenya full
		bool full() {
			//kondisi jika head berada di ujung kanan dan tail berada di ujung kiri 
			//yang tidak memungkinkan untuk menjalankan kondisi dibawah
			if (head == 5 && tail == 0) {
				return true;
			}
			if (head == tail - 1) {
				return true;
			} return false;
		}

		//menambah element beserta memajukan penunjuk indexnya (head)
		void enqueue(int val) {
			if (full()) {
				cout << "full" << endl;
			}
			else {
				arr[head] = val;
				head++;
				if (head == 6) {
					head = 0;
				}
			}
		}
		
		//memajukan penunjuk indexnya (tail) , tanpa menghapus element
		void dequeue() {
			if (empty()) {
				cout << "empty" << endl;
			}
			else {
				tail++;
				if (tail == 6) {
					tail = 0;
				}
			}
		}

		//menampilkan isi dari queue dengan modulus 5 yang itu adalah batas max dari arraynya
		void print() {
			int i;
			if (empty()) {
				cout << endl
					<< "empty" << endl;
			}
			else {
				for (i = tail; i != head; i++ % 5)	{
					cout << arr[i] << "\t";
				}
				cout << endl;
			}
		}
};

int main() {
	queue q;

	q.dequeue();

	q.enqueue(3);
	q.print();

	q.enqueue(5);
	q.print();

	q.enqueue(7);
	q.print();

	q.enqueue(9);
	q.print();

	q.enqueue(11);
	q.print();
	
	q.enqueue(13);
	q.print();

	q.dequeue();
	q.print();
}