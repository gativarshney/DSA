class Solution{
    public:
        vector<int> arr;
        int cnt;
        void initializeHeap(){
            cnt = 0;
        }

        void heapifyDown(int idx){
            int smallest = idx;
            int leftChild = 2 * idx + 1;
            int rightChild = 2 * idx + 2;
            if(leftChild < cnt && arr[leftChild] < arr[smallest]){
                smallest = leftChild;
            }
            if(rightChild < cnt && arr[rightChild] < arr[smallest]){
                smallest = rightChild;
            }
            if(idx != smallest){
                swap(arr[smallest], arr[idx]);
                heapifyDown(smallest);
            }
        }

        void heapifyUp(int idx){
            int parent = (idx - 1) / 2;
            if(idx > 0 && arr[idx] < arr[parent]){
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
            if(index >= cnt) return;
            arr[index] = new_val;
            if (index > 0 && arr[index] < arr[(index - 1) / 2]) {
                heapifyUp(index);
            } else {
                heapifyDown(index);
            }
        }

        void extractMin(){
            if(cnt == 0) return;
            swap(arr[0], arr[cnt-1]);
            arr.pop_back();
            cnt--;
            heapifyDown(0);
        }

        bool isEmpty(){
            if(cnt == 0) return true;
            return false;
        }

        int getMin(){
            if(cnt == 0) return -1;
            return arr[0];
        }

        int heapSize(){
            return cnt;
        }
};