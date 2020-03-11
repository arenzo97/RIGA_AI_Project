library(Rserve)
library(plotrix)

this.dir <- dirname(parent.frame(2)$ofile)
setwd(this.dir)


arr1<-c(9,1,2,1,1,1,10,8,9)
arr2<-c(11,3,2,2,3,4,9,9,8)

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

  
  return(result);
}

xi_df <-Xi_ClusterAttributes(td)
xi_df
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

ReturnClusterXY<-function(df,cluster_value)
{
  result <- subset(df,df$clusters == cluster_value)
  
  return(result)
}


#Circle FIT
ReturnSxList<-function(nList)
{
  resList <- c()
  for (i in 1:length(nList))
  {
    Sn <- ReturnSx(nList[i],nList)
    resList<-c(resList,Sn)
  }
  
  
  return(resList)
}

ReturnSx<-function(nvalue,nList)
{
  result = nvalue - (sum(nList)/length(nList))
  return(result)
}

CircleFitRawValues<-function(xiList,yiList)
{
  xi<-xiList
  yi<-yiList
  
  ui<-ReturnSxList(xiList)
  vi<-ReturnSxList(yiList)
  
  uu<-c()
  vv<-c()
  uv<-c()
  vu<-c()
  
  uuu<-c()
  vvv<-c()
  uvv<-c()
  vuu<-c()
  
  for(i in 1:length(xiList))
  {
    uu<-c(uu,(ui[i]^2))
    vv<-c(vv,(vi[i]^2))
    uv<-c(uv,(ui[i] * vi[i]))
    vu<-c(vu,(vi[i] * ui[i]))
    
    uuu<-c(uuu,(ui[i]^3))
    vvv<-c(vvv,(vi[i]^3))
    uvv<-c(uvv,(ui[i]*(vi[i]^2)))
    vuu<-c(vuu,(vi[i]*(ui[i]^2)))
    
  }
  
  df<-cbind(xi,yi,ui,vi,uu,vv,uv,vu,uuu,vvv,uvv,vuu)
  res_df<-as.data.frame(df)
  
  return(res_df)
}

CircleFitSummed<-function(df)
{
  Sx <- sum(df$xi)
  Sy <- sum(df$yi)
  
  Suu <- sum(df$uu)
  Svv <- sum(df$vv)
  Suv <- sum(df$uv)
  Svu <- sum(df$vu)
  
  Suuu <- sum(df$uuu)
  Svvv <- sum(df$vvv)
  Suvv <- sum(df$uvv)
  Svuu <- sum(df$vuu)
  
  numRows<-nrow(df)
  
  summedarray <- cbind(Sx,Sy,Suu,Svv,Suv,Svu,Suuu,Svvv,Suvv,Svuu,numRows)
  summeddf <- as.data.frame(summedarray)
  
  return(summeddf)
}

CircleFitMatrix<-function(summed_df)
{
 
  A <- matrix(nrow=2,ncol=2,0);
  A[1,1] <- summed_df$Suu;
  A[1,2] <- summed_df$Suv;
  A[2,1] <- summed_df$Svu;
  A[2,2] <- summed_df$Svv;
  b <- matrix(nrow=2,ncol=1,0);
  b[1,1] <- 0.5*(summed_df$Suuu + summed_df$Suvv);
  b[2,1] <- 0.5*(summed_df$Svvv + summed_df$Svuu);
  
  z <- solve(A)%*%b;
  uc <- z[1,1];
  vc <- z[2,1];
  
  xc = uc+(summed_df$Sx/summed_df$numRows)
  yc= vc+(summed_df$Sy/summed_df$numRows)
 # radius
  centre_array<-cbind(uc,vc,xc,yc)
  centre_df<-as.data.frame(centre_array)
  centre_df<-cbind(summed_df,centre_df)
  return(centre_df)
}

ReturnRadius<-function(df,n)
{
  radius <- sqrt(df$uc*df$uc + df$vc*df$vc + (df$Suu+df$Svv)/n);
  return(radius)
}

CircleFitFull<-function(xi,yi)
{
  cf_raw <- CircleFitRawValues(xi,yi)
  cf_summed<-CircleFitSummed(cf_raw)
  cf_centre<-CircleFitMatrix(cf_summed)
  radius<-ReturnRadius(cf_centre,nrow(cf_raw))
  
  cf_result<-cbind(cf_centre,radius)
  return(cf_result)
}


#CIRCLE FIT TEST RESULTS
test_xi<-c(0,0.5,1,1.5,2,2.5,3)
test_yi<-c(0,0.25,1,2.25,4,6.25,9)
test_CF<-CircleFitRawValues(test_xi,test_yi)
testSummed<-CircleFitSummed(test_CF)
test_centre<-CircleFitMatrix(testSummed)
test_radius<-ReturnRadius(test_centre,7)

testFull<-CircleFitFull(test_xi,test_yi)
df_test_CF<-as.data.frame(test_CF)

CF_cluster1CSV<-CircleFitFull(Cluster1$xi,Cluster1$yi)
CF_cluster2CSV<-CircleFitFull(Cluster2$xi,Cluster2$yi)

plot(draw.circle(testFull$xc,testFull$yc,testFull$radius))

plot(draw.circle(CF_cluster1CSV$xc,CF_cluster1CSV$yc,CF_cluster1CSV$radius));draw.circle(CF_cluster2CSV$xc,CF_cluster2CSV$yc,CF_cluster2CSV$radius)

plot(c(1,1))

# IMPORT AND EXPORT CSV
ExportToCSV<-function(df,filename)
{
  write.csv(df,paste0("data/",filename),row.names = FALSE)
}


xi_csv = read.csv('data/pixels/xi.csv', sep=",",header = FALSE)
yi_csv = read.csv('data/pixels/yi.csv', sep=",",header = FALSE)


xi_csv1 = read.csv('data/pixels/test/1-2_xi.csv', sep=",",header = FALSE)
yi_csv1 = read.csv('data/pixels/test/1-2_yi.csv', sep=",",header = FALSE)
csvdf1 <- BindXY_CSV(xi_csv1,yi_csv1)

csvdf <- BindXY_CSV(xi_csv,yi_csv)
csvdf_bind<-HCluster_C2(csvdf1)
Cluster1<-ReturnClusterXY(csvdf_bind,1)
Cluster2<-ReturnClusterXY(csvdf_bind,2)

xi_df

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
  result<-cbind(clusters,df)
  
  return(result);
}

#Test Values

csv_xi_to_Su <-ReturnSxList(xi)
csv_yi_to_Sv<-ReturnSxList(yi)




test_xi = c(0,0.5,1,1.5,2,2.5,3)
test_xi_real= c(-1.5,-1,-0.5,0,0.5,1,1.5)

testReturnSu<-ReturnSxList(test_xi)

u2 = UNIT_TEST_ReturnSx(ReturnSx(0,test_xi),0)



UNIT_TEST_ReturnSx<-function(xy,uv)
{
  if(xy==uv)return(TRUE)
  else return(FALSE)
}

