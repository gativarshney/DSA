class Solution{
    public:
        vector<int> arr;
        int cnt;

        void initializeHeap(){
            cnt = 0;
        }

        void heapifyDown(int idx){
            int largest = idx;
            int leftChild = 2 * idx + 1;
            int rightChild = 2 * idx + 2;

            if(leftChild < cnt && arr[leftChild] > arr[largest]){
                largest = leftChild;
            }
            if(rightChild < cnt && arr[rightChild] > arr[largest]){
                largest = rightChild;
            }
            if(largest != idx){
                swap(arr[largest], arr[idx]);
                heapifyDown(largest);
            }
        }

        void heapifyUp(int idx){
            int parent = (idx - 1)/2;
            if(idx > 0 && arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]);
                heapifyUp(parent);
            }
        }

        void insert(int key){
            arr.push_back(key);
            cnt++;
            heapifyUp(cnt-1);
        }

        void changeKey(int index, int new_val){
            arr[index] = new_val;
            if(index > 0 && arr[index] > arr[(index - 1) / 2]){
                heapifyUp(index);
            }
            else{
                heapifyDown(index);
            }
        }

        void extractMax(){
            swap(arr[0], arr[cnt - 1]);
            arr.pop_back();
            cnt--;
            heapifyDown(0);
        }

        bool isEmpty(){
            return (cnt == 0);
        }

        int getMax(){
            return arr[0];
        }

        int heapSize(){
            return cnt;
        }
};