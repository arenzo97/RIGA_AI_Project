library(Rserve)

Test<-function()
{
  print("Hello World")
}


Test2<-function(a)
{
  return(a)
}

MatrixInverse<-function(a)
{
# print("Hello World")
  A=matrix(nrow=2,ncol=2);
  b=matrix(nrow=2,ncol=1);
  
  A[1,1]=a[1]
  A[1,2]=a[2]
  A[2,1]=a[4]
  A[2,2]=a[5]
  b[1]=a[3]
  b[2]=a[6]
  
  res=solve(A)%*%b
  return (res)
  
}

ConnectionTest<-function()
{
  print("Connection Successful")
}

Test3<-function(a)
{
  print(a)
}




TestReturnDoubleList<-function(arr)
{
  return(sum(arr))

}




TestReturnDoubleList2<-function(arr,arr2)
{
  result = as.matrix(cbind(arr,arr2))
  return(result)
}

arr1<-c(1,2,3)
arr2<-c(3,2,1)

TestReturnDoubleList2(arr1,arr2)




HCluster_C<-function(xi,yi)
{
  
  result = as.matrix(cbind(xi,yi))
  
  clusters <- hclust(dist(result),method="single");
  clusters <- cutree(clusters,2);
  print(clusters);
  plot(bc[,1],bc[,2], col = clusters);
  
  
  return(sum(result[,2]));
}



fitSS <- function(xy,
                  a0=mean(xy[,1]),
                  b0=mean(xy[,2]),
                  r0 = mean(sqrt((xy[,1]-a0)^2 + (xy[,2]-b0)^2)),
                  ...){
  SS <- function(abr){
    sum((abr[3] - sqrt((xy[,1]-abr[1])^2 + (xy[,2]-abr[2])^2))^2)
  }
  optim(c(a0,b0,r0), SS, ...)
}
CircleFit<-function(xList,yList)
{
  
  for(i in xList.size())
  {
    
  }
}