library(Rserve)

this.dir <- dirname(parent.frame(2)$ofile)
setwd(this.dir)


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

arr1<-c(9,1,2,1,1,1,10,8,9)
arr2<-c(11,3,2,2,3,4,9,9,8)

d<-HCluster_C(arr1,arr2)
td = read.csv('data/test.csv', sep=",",header = TRUE)

tdarr<-c(td$xi,td$yi)
td<-HCluster_C(td)


HCluster_C<-function(df)
{
  
  result = cbind(df$xi,df$yi)
  
  
  clusters <- hclust(dist(result),method="single");
  clusters <- cutree(clusters,2);
  df$clusters=clusters


  plot(result[,1],result[,2], col = clusters);

  
  return(df);
}

xi_df <-Xi_ClusterAttributes(td)

Xi_ClusterAttributes<-function(df)
{
  clusters = df$clusters
  xi = df$xi
  result <- cbind(clusters,xi)
  return(result)
}
Yi_ClusterAttributes<-function(df)
{
  clusters = df$clusters
  xi = df$yi
  result <- cbind(clusters,xi)
  return(result)
}

Cluster1 <- ReturnClusterXY(td,1)
Cluster2 <- ReturnClusterXY(td,2)

ReturnClusterXY<-function(df,cluster_value)
{
  result <- subset(df,df$clusters == cluster_value)
  
  return(result)
}
#filename = "test3.csv"
#ExportToCSV(td,filename)

ExportToCSV<-function(df,filename)
{
  write.csv(df,paste0("data/",filename),row.names = FALSE)
}

xi_csv = read.csv('data/pixels/xi.csv', sep=",",header = FALSE)
yi_csv = read.csv('data/pixels/yi.csv', sep=",",header = FALSE)

csvdf <- BindXY_CSV(xi_csv,yi_csv)
HCluster_C2(csvdf)

BindXY_CSV<-function(x,y)
{
  xi <-x
  yi <- y
  df <- cbind(xi,yi)
  
  colnames(df)<-c("xi","yi")
  return(df)
}

HCluster_C2<-function(df)
{
  
  result = cbind(df$xi,df$yi)
  
  
  clusters <- hclust(dist(result),method="single");
  clusters <- cutree(clusters,2);
  #df$clusters=clusters
  
  
  plot(result[,1],result[,2], col = clusters);
  
  
  return(df);
}
