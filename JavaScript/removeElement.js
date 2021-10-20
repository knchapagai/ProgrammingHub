var removeElement = function(nums, val) {
  const len = nums.length;
  for(i = 0; i < len; i++) {
    if(i > nums.length - 1) {
      break;
    }
    if (nums[i] === val) {
      nums.splice(i, 1);
      i--;
    }
  }
  return nums.length;
};
