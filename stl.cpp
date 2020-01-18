#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
const long long INT_MAX = 1e5 + 10;

using namespace std;

void vectorDemo() {
// 	std::vector      

// 	NOTES:
// 	1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 	2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// 	ELEMENT ACCESS
// 	at(), [], front(), back(), data()

// 	MODIFIERS:
// 	insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()
	
	vector<int> A = {1, 2, 3, 8, 4, 9, 10, 0};
	sort(A.begin(), A.end());
	
	cout << binary_search(A.begin(), A.end(), 3); //O(NlogN)
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);
	
	vector<int>::iterator itr = upper_bound(A.begin(), A.end(), 100);//>
	auto itr2 = lower_bound(A.begin(), A.end(), 100); //>=
	cout << itr - itr2 <<"\n"; //Occurence count 
	
	//Traversing using itr...tradition method
	for(itr = A.begin(); itr < A.end(); ++itr) cout << *itr << " ";
	
	cout <<"\n";
	//third method
	for(int &x : A) { //&x for globally changing the values
		x++;
		cout << x <<" ";
	}
	
	cout << "\nAuto Traversing";
	//Traversing using auto keyword
	for(auto &itr : A) cout << itr <<" ";
}

void setDemo() {
	/*SET is used when:
	Consider we need a container with the following features:

		add an element, but do not allow duples [duplicates?] - O(logN)

		remove elements - O(logN)

		get count of elements (distinct elements) -  O(1)

		check whether elements are present in set - O(logN)
	*/
	
	set<int> S;
	S.insert(1);
	S.insert(3);
	S.insert(2);
	S.insert(-2);
	S.insert(-10);
	
	for(int x: S) cout << x <<" ";//O(logN) //-10 -2 1 2 3
	//Sorted order...no sort reqd as compared to vectors
	cout <<"\n";
	
	auto itr = S.find(100);
	if(itr == S.end()) cout <<"Not Present\n";
	else {
		cout << "Present\n";
		cout << *itr <<"\n";
	}
	
	auto itr2 = S.lower_bound(-1111);
	auto itr3 = S.upper_bound(2);
	cout << *itr2 <<" " << *itr3<<"\n";
	
	if(itr3 == S.end()) cout << "End!";
	
	S.erase(-2);
	S.erase(0);//no runtime error given. just ignores
	for(int x: S) cout << x <<" ";
}

void mapDemo() {
	map<int, int> A; //Mapping takes O(logN) time
	A[1] = 100;
	A[2] = 200;
	A[4] = 400;
	
	map<char, int> cnt;
	string x = "Saurav";
	
	for(char c: x) {
		cnt[c]++;
	}
	cout << cnt['a'] <<"\n";
}

void PowerOfStl() {
	/*
	add[10, 100]
	add[250, 300]
	give me the interval of 267
	*/ 
	set< pair<int, int> > S;
	S.insert({401, 450});
	S.insert({10, 20});
	S.insert({30,400});
	S.insert({2,3});
	
	int point = 11;
	
	auto itr = S.upper_bound({point, INT_MAX});
	if(itr == S.begin()) {
		cout <<"Not in range\n";
		return 0;
	}
	
	itr--;
	pair<int, int> current = *itr;
	if(current.first <= point && point <= current.second) {
		cout <<"Present " << current.first <<" " << current.second<<'\n';
	}
	else {
		cout <<"Not Present";
	}
}

int main() {
	
	return 0;
}
