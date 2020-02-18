library(Rserve)
Rserve()

Test<-function()
{
  print("Hello World")
}


Test2<-function(a)
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


HierarchicalPlot<-function(idata,fitMethod)
{
  df <- data.frame(idata)
  d <- dist(df, method = "euclidean")
  fit <- hclust(d, method = fitMethod)
  plot(fit)

  return(fit)
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