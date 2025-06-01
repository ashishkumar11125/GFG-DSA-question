class Solution:
	def front(self,i,j,n):
	    i=i+(j+1)//n
        j=(j+1)%n
        return i,j
    
    def back(self,p,q,n):
        q=(q-1)%n
        p=p-(q+1)//n
        return p,q

    def countPairs(self, mat1, mat2, x):
        n=len(mat1)
        i,j,p,q,ans=0,0,n-1,n-1,0
        while i<n and j<n and p>=0 and q>=0:
            total=mat1[i][j]+mat2[p][q]
            if total>x:
                p,q=self.back(p,q,n)
            elif total<x:
                i,j=self.front(i,j,n)
            else:
                p,q=self.back(p,q,n)
                i,j=self.front(i,j,n)
                ans+=1
        return ans