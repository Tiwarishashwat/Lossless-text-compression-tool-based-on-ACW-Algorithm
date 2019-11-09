// C program for Huffman Coding
// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HTT 127

// A Huffman tree node
struct MinimumHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child of this node
	struct MinimumHeapNode *left, *right;
};

// A Min Heap: Collection of
// min-heap (or Huffman tree) nodes
struct MinimumHeap {

	// Current size of min heap
	unsigned size;

	// capacity of min heap
	unsigned capacity;

	// Array of MinimumHeap node pointers
	struct MinimumHeapNode** array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinimumHeapNode* newerNode(char data, unsigned freq)
{
	struct MinimumHeapNode* temp
		= (struct MinimumHeapNode*)malloc
(sizeof(struct MinimumHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

// A utility function to create
// a min heap of given capacity
struct MinimumHeap* createMinimumHeap(unsigned capacity)

{

	struct MinimumHeap* MinimumHeap
		= (struct MinimumHeap*)malloc(sizeof(struct MinimumHeap));

	// current size is 0
	MinimumHeap->size = 0;

	MinimumHeap->capacity = capacity;

	MinimumHeap->array
		= (struct MinimumHeapNode**)malloc(MinimumHeap->
capacity * sizeof(struct MinimumHeapNode*));
	return MinimumHeap;
}

// A utility function to
// swap two min heap nodes
void swapMinimumHeapNode(struct MinimumHeapNode** a,
					struct MinimumHeapNode** b)

{

	struct MinimumHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// The standard MinimumHeapify function.
void MinimumHeapify(struct MinimumHeap* MinimumHeap, int idx)

{

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < MinimumHeap->size && MinimumHeap->array[left]->
freq < MinimumHeap->array[smallest]->freq)
		smallest = left;

	if (right < MinimumHeap->size && MinimumHeap->array[right]->
freq < MinimumHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinimumHeapNode(&MinimumHeap->array[smallest],
						&MinimumHeap->array[idx]);
		MinimumHeapify(MinimumHeap, smallest);
	}
}

// A utility function to check
// if size of heap is 1 or not
int isSizeONE(struct MinimumHeap* MinimumHeap)
{

	return (MinimumHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
struct MinimumHeapNode* extractMinimum(struct MinimumHeap* MinimumHeap)

{

	struct MinimumHeapNode* temp = MinimumHeap->array[0];
	MinimumHeap->array[0]
		= MinimumHeap->array[MinimumHeap->size - 1];

	--MinimumHeap->size;
	MinimumHeapify(MinimumHeap, 0);

	return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinimumHeap(struct MinimumHeap* MinimumHeap,
				struct MinimumHeapNode* MinimumHeapNode)

{

	++MinimumHeap->size;
	int i = MinimumHeap->size - 1;

	while (i && MinimumHeapNode->freq < MinimumHeap->array[(i - 1) / 2]->freq) {

		MinimumHeap->array[i] = MinimumHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	MinimumHeap->array[i] = MinimumHeapNode;
}

// A standard function to build min heap
void buildMinimumHeap(struct MinimumHeap* MinimumHeap)

{

	int n = MinimumHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		MinimumHeapify(MinimumHeap, i);
}

// A utility function to print an array of size n

// Utility function to check if this node is leaf
int isLEaf(struct MinimumHeapNode* root)

{

	return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinimumHeap* createAndBuildMinimumHeap(char data[], int freq[], int size)

{

	struct MinimumHeap* MinimumHeap = createMinimumHeap(size);

	for (int i = 0; i < size; ++i)
		MinimumHeap->array[i] = newerNode(data[i], freq[i]);

	MinimumHeap->size = size;
	buildMinimumHeap(MinimumHeap);

	return MinimumHeap;
}

// The main function that builds Huffman tree
struct MinimumHeapNode* buildingHuffmanTree(char data[], int freq[], int size)

{
	struct MinimumHeapNode *left, *right, *top;

	// Step 1: Create a min heap of capacity
	// equal to size. Initially, there are
	// modes equal to size.
	struct MinimumHeap* MinimumHeap = createAndBuildMinimumHeap(data, freq, size);

	// Iterate while size of heap doesn't become 1
	while (!isSizeONE(MinimumHeap)) {

		// Step 2: Extract the two minimum
		// freq items from min heap
		left = extractMinimum(MinimumHeap);
		right = extractMinimum(MinimumHeap);

		// Step 3: Create a new internal
		// node with frequency equal to the
		// sum of the two nodes frequencies.
		// Make the two extracted node as
		// left and right children of this new node.
		// Add this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = newerNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinimumHeap(MinimumHeap, top);
	}

	// Step 4: The remaining node is the
	// root node and the tree is complete.
	return extractMinimum(MinimumHeap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void decode_file(struct MinimumHeapNode* root)
{
	FILE *f1,*f2;
	char ch;
	f1=fopen("huff_net.txt","r");
	f2=fopen("orignal.txt","w");
    struct MinimumHeapNode* curr = root;
		while((ch=fgetc(f1))!=EOF)
		{
			if (ch == '0')
				 curr = curr->left;
			else
				 curr = curr->right;
			// reached leaf node
      if (curr->left==NULL && curr->right==NULL)
       {
				 fprintf(f2,"%c",curr->data);
         curr = root;
       }
		}
		fclose(f1);
		fclose(f2);
}
// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void call_decoder(char data[], int freq[], int size)
{
	int ans=0;
	struct MinimumHeapNode* root = buildingHuffmanTree(data, freq, size);
	printf("Press 1 to decode:");
	scanf("%d",&ans);
	if (ans==1)
	{
	  decode_file(root);
		printf("File decoded successfully");
	}
	else
	{
		printf("Wrong input!");
	}
}
