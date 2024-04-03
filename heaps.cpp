#include <bits/stdc++.h>
using namespace std;

int parent(int i){
	return (i-1)/2;
}

void insert(vector<int>&ar, int k){
	ar.push_back(k);
	for(int i = ar.size()-1;i!=0 and ar[i] < ar[parent(i)];i = parent(i)){
		swap(ar[i], ar[parent(i)]);	
	}
}


void heapify(vector<int>&ar, int i){
	if(i>=ar.size())
		return;

	int left = 2*i+1;
	int right = 2*i+2;
	int smallest = i;
	int size = ar.size();

	if(left < size and ar[i] > ar[left])
		smallest = left;
	if(right < size and ar[smallest] > ar[right])
		smallest = right;
	if(smallest != i){
		swap(ar[i], ar[smallest]);
		heapify(ar, smallest);
	}
}

int extractMin(vector<int>&ar){
	int size = ar.size();
	int ans = ar[0];
	swap(ar[0], ar[size-1]);
	ar.pop_back();
	heapify(ar, 0);
	return ans;
}

int decreaseKey(vector<int>&ar, int i, int x){
	ar[i] = x;
	while(i!=0 and ar[i]<ar[parent(i)]){
		swap(ar[i], ar[parent(i)]);
		i = parent(i);
	}
	return ar[i];
}

void deleteKey(vector<int>&ar, int i){
	decreaseKey(ar, i, INT_MIN);
	extractMin(ar);
}

void buildHeap(vector<int>&ar){
	for(int i = (ar.size()-2)/2;i>=0;i--){
		heapify(ar, i);
	}
}

int main(){
	int n;
	cin >> n;

	vector<int> ar(n);
	for(int i = 0;i<n;i++)
		cin >> ar[i];

	buildHeap(ar);
	for(int i = 0;i<ar.size();i++)
		cout << ar[i] << " ";

	insert(ar, 0);
	insert(ar, 6);
	insert(ar, 7);
	cout << "min: " << extractMin(ar) << "\n";
	for(int i = 0;i<ar.size();i++)
		cout << ar[i] << " ";
	deleteKey(ar, 0);
	for(int i = 0;i<ar.size();i++)
		cout << ar[i] << " ";
	cout << "min: " << extractMin(ar) << "\n";
}