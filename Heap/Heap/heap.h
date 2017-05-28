




void Test()
{
	int array[] = {53,17,78,9,45,65,87,23};
	//Heap<int,Greater<int>> h(array,sizeof(array)/sizeof(array[0]));
	Heap<int, Greater> h(array, sizeof(array) / sizeof(array[0]));

	//h.Remove();
	h.Insert(0);
	h.Remove();
	//h.HeapSort();
	//cout << h.Size() << endl;

}

