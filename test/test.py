import collections

class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        tmpDict = collections.defaultdict(int)
        self.helper(root, tmpDict)
        return [key for key in tmpDict.keys() if tmpDict[key] == max(tmpDict.values())]

    def helper(self, root, tmpDict):
        if root is None:
            return
        tmpDict[root.val] += 1
        self.helper(root.left, tmpDict)
        self.helper(root.right, tmpDict)


def main(nums):
    tmp = list(set(nums))
    nums.clear()
    nums.append(tmp)
    nums[:] = [22, 33, 44]
    return len(nums)

if __name__ == '__main__':
    nums = [1, 2, 2, 3, 3]
    ret = main(nums)
    print(ret)
    print(nums)
    a = 2
