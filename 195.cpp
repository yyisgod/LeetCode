class Solution { 
public: 
	void rotate(vector<int>& nums, int k) { 
		int arrLen = nums.size();

		if (k >= arrLen){
    	    k = k % arrLen;
    	}

    	if (!arrLen){
    	    return;
    	}

    	if (k == 0){
    	    return;
    	}

    	int firstVal = nums[0];
    	int firstIndex = 0;

    	int emptyIndex = firstIndex;

    	for (int i = 0; i < arrLen; i++){
    	    int correspondingIndex = (emptyIndex + arrLen - k) % arrLen;
    	    if (correspondingIndex == firstIndex){
    	        nums[emptyIndex] = firstVal;
    	        firstIndex++;
    	        firstVal = nums[firstIndex];
    	        emptyIndex = firstIndex;
    	    } else {
    	        nums[emptyIndex] = nums[correspondingIndex];
    	        emptyIndex = correspondingIndex;
    	    }
    	}
	}
};
