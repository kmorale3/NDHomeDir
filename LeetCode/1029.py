class Solution(object):
    def destroyTargets(self, nums, space):
        """
        :type nums: List[int]
        :type space: int
        :rtype: int
        """
        targets, minVal = self.checkDestroy(nums, space, 0)
        printStr = 'The minimum value seed that destroys the most targets (' + str(targets) + ') is ' + str(minVal)
        print(printStr)
        return minVal
        
    def checkDestroy(self,nums, space, index):
        
        if index >= len(nums):
            return 0, index
        
        targets, value = self.checkDestroy(nums, space, index + 1)
        myTargets = 0
        for num in nums:
            if not (num - nums[index]) % space:
                myTargets = myTargets + 1
        if targets > myTargets:
            return targets, value
        elif myTargets > targets:
            return myTargets, nums[index]
        else:
            return targets, min(value, nums[index])