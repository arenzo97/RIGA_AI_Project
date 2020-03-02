library(Rserve)
library()
install.packages("plotrix")
library(plotrix)

Test<-function()
{
  print("Hello World")
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

PlotPoints<-function()
{
  #plot()
  ui<-c(0,0.5,1,1.5,2,2.5,3)
  yi<-c(0,0.25,1,2.25,4,6.25,9)
  plot(ui,yi)
  draw.circle(-11.839,5.1964,14.686)
}
PlotPoints()



HierarchicalPlot<-function(xi,yi,listSize)
{
  c1 <- NULL;
    for (i in listSize)
  {
    x<- xi[i]
    y<- yi[i]
    c1 <- rbind(c1,c(x,y));
  }
 
  clusters <- hclust(dist(c1),method="single");
  clusters <- cutree(clusters,2);
  print(clusters);
  plot(bc[,1],bc[,2], col = clusters);
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