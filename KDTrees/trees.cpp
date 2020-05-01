/* Trees.cpp
 * Contains all of the definitions of the methods declared in trees.h. 
 */
#include "trees.h"

using namespace std;

datapoint::datapoint(){
    data[0] = -1;
    data[1] = -1;
    data[2] = -1;
    data[3] = -1;
} //datapoint()
void datapoint::newData(){
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    data[0] = w;
    data[1] = x;
    data[2] = y;
    data[3] = z;
} // newData()
node::node(){
    internal = 0; // assume leaf
    value = -1;
    dim = -1;
    left = NULL;
    right = NULL;
} // node()
KDtree::KDtree(){
    root = NULL;
}
void KDtree::setRoot(node *leaf){
    root = leaf;
} // setRoot(node *leaf)
void node::makeBucket(datapoint points[], int size){
    for(int i = 0; i < size; i++){
	allpoints.push_back(points[i]); 
    }	
} // makeBucket(datapoint points[], int size)
void node::makeInternal(datapoint array[], int size){
    int wmin = 1000; int xmin = 1000; int ymin = 1000; int zmin = 1000;
    int wmax = 0; int xmax = 0; int ymax = 0; int zmax = 0;
    for(int i = 0; i < size; i++){
        // Check mins
	if(array[i].data[0] < wmin)
	    wmin = array[i].data[0];
	if(array[i].data[1] < xmin)
	    xmin = array[i].data[1];
	if(array[i].data[2] < ymin)
	    ymin = array[i].data[2];
	if(array[i].data[3] < zmin)
	    zmin = array[i].data[3];
	// Check maxes
	if(array[i].data[0] > wmax)
	    wmax = array[i].data[0];
	if(array[i].data[1] > xmax)
	    xmax = array[i].data[1];
    	if(array[i].data[2] > ymax)
	    ymax = array[i].data[2];
	if(array[i].data[3] > zmax)
	    zmax = array[i].data[3];
    }
    // Find range to discriminate on
    int rangew = wmax - wmin;
    int rangex = xmax - xmin;
    int rangey = ymax - ymin;
    int rangez = zmax - zmin;
    int range[4] = {rangew, rangex, rangey, rangez};
    int maxrange = 0;
    for(int i = 0; i < 4; i++)
    {
	if(maxrange < range[i]){
	    dim = i;
	    maxrange = range[i];
	}
    }
    KDtree KDtemp;
    // Set values for the node
    int left = 0;
    int right = size - 1;
    int medIndex = (right-left)/2 + left;
    int median = KDtemp.quickselect(dim, array, left, right, medIndex); 
    value = median;
    internal = 1;
} // makeInternal(datapoint array[], int size)
int KDtree::partition(int dim, datapoint array[], int leftIndex, 
int rightIndex, int pivotIndex){
    int pivot = array[pivotIndex].data[dim];
    // Swap the pivot data and end data
    datapoint temp = array[pivotIndex];
    array[pivotIndex] = array[rightIndex];
    array[rightIndex] = temp;
    // For every element less than the pivot, leftPivot is incremented
    // and the current element is placed before the pivot.
    int leftPivot = leftIndex;
    for(int i = leftIndex; i < rightIndex; i++)
    {
	    if(array[i].data[dim] <= pivot)
	    {
		    temp = array[i];
		    array[i] = array[leftPivot];
		    array[leftPivot] = temp;
		    leftPivot++;
	    }
    }
    // Move pivot to final destination
    temp = array[leftPivot];
    array[leftPivot] = array[rightIndex];
    array[rightIndex] = temp;
    return leftPivot;
} // partition(int dim, datapoint array[], int leftIndex, int rightIndex, 
//   int pivotIndex)
int KDtree::quickselect(int dim, datapoint array[], int leftIndex, 
int rightIndex, int medIndex){
    // If the array is only one element
    if(leftIndex == rightIndex)
	return array[leftIndex].data[dim];
    // Random pivot index between right and left
    int rand;
    cin >> rand;
    int pivotIndex = leftIndex + rand % (rightIndex- leftIndex + 1);
    pivotIndex = partition(dim, array, leftIndex, rightIndex, pivotIndex);
    // Determine the median index. If even number of elements, the left
    // of the middle elements is chosen.
    if (medIndex == pivotIndex)
	return array[medIndex].data[dim];
    else if (medIndex < pivotIndex)
	return quickselect(dim, array, leftIndex, pivotIndex-1, medIndex);
    else
	return quickselect(dim, array, pivotIndex+1, rightIndex, medIndex);
} // quickselect(int dim, datapoint array[], int leftIndex, int rightIndex, 
//   int medIndex)
void node::leftBucket(datapoint array[], int size, node *internal){
    for(int i = 0; i < size; i++){
    	if (array[i].data[internal->dim] <= internal->value){
	    allpoints.push_back(array[i]);
	}
    }
} // leftBucket(datapoint array[], int size, node *internal)
void node::rightBucket(datapoint array[], int size, node *internal){
    for(int i = 0; i < size; i++){
    	if (array[i].data[internal->dim] > internal->value)
	    allpoints.push_back(array[i]);
    }
} // rightBucket(datapoint array[], int size, node *internal)
void KDtree::addLeaf(node *leftleaf, node *rightleaf, node *parent){
    parent->left = leftleaf;
    parent->right = rightleaf;
} // addLeaf(node *leftleaf, node *rightleaf, node *parent)
// In the case that a bucket has more than 10 elements, the node must
// be transformed into an internal node and two buckets of data made from
// the current data. This will continue until no buckets contain
// excess data.
void KDtree::transform(node *tform){
    int n = tform->allpoints.size();
    if(n > 10)
    {
	tform->internal = 1;
	datapoint *temp = new datapoint[n];
	for (int i = 0; i < n; i++){
	    temp[i] = tform->allpoints[i];
	}
	tform->makeInternal(temp, n);
	node *leftBucket = new node;
	node *rightBucket = new node;
	leftBucket->leftBucket(temp, n, tform);
	rightBucket->rightBucket(temp, n, tform);
	tform->left = leftBucket;
	tform->right = rightBucket;
	transform(leftBucket);
	transform(rightBucket);	
    }
} // transform(node *tform)
// Dive the tree until the proper bucket is found then print the bucket.
void KDtree::probeDive(datapoint probe, int numprobes){
    node *current = new node;
    current = root;
    while(current != NULL){
        if(current->internal == 0){
            current->printBucket();
	    return;
	}
        else{
	    if(current->value >=  probe.data[current->dim])
	        current = current->left;
	    else
		current = current->right;
	}
    }
} // probeDive(datapoint probe, int numprobes)
void node::printBucket(){
    for (auto i = allpoints.begin(); i < allpoints.end(); i++){
        for (int j = 0; j < DIMENSIONS; j++){
	    cout << (*i).data[j] << " "; 
	}
	cout << endl;	
    }
} // printBucket()
void datapoint::printProbe(){
    cout << "Probe ";
    cout << data[0] << " " << data[1] << " " << data[2] << " " << data[3];
    cout << " reaches bucket" << endl;
} // printProbe() 
