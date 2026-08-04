class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        mn=min(nums)
        mx=max(nums)
        a=[]
        for i in range(mn,mx):
            if not i in nums:
                a.append(i)
        return a