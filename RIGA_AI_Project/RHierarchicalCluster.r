library(Rserve)
Rserve()

Test<-function()
{
  print("Hello World")
}

HierarchicalPlot<-function(idata,fitMethod)
{
  d <- dist(idata, method = "euclidean")
  fit <- hclust(d, method = fitMethod)
  plot(fit)
  Hgroups <-cutree(fit,k=5)
  rect.hclust(fit,k=5, border="red")
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
  print("Hello World")
}