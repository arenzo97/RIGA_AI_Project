c1 <- NULL;
c2 <- NULL;
TT <- 75:100;
TT <- TT / 100;
TT <- TT * 2 * 3.142;
x0 <- 5.0;
y0 <- 5.0;
r0 <- 2.5;
x1 <- 4.75;
y1 <- 4.75;
r1 <- 1.5;
for (t in TT)
{
  x <- r0 * cos(t) + x0;
  y <- r0 * sin(t) + y0;
  c1 <- rbind(c1,c(x,y));
  
  x <- r1 * cos(t) + x1;
  y <- r1 * sin(t) + y1;
  c2 <- rbind(c2,c(x,y));
}
#print(c2);
bc <- rbind(c1,c2);

clusters <- hclust(dist(bc),method="single");
clusters <- cutree(clusters,2);
print(clusters);
plot(bc[,1],bc[,2], col = clusters);
#plot(bc[,1],bc[,2]);

#Fit circle one...

xbar <- mean(c2[,1]);
ybar <- mean(c2[,2]);
u <- c2[,1] - xbar;
v <- c2[,2] - ybar;
N <- length(v);
suu <- 0
suv <- 0;
svv <- 0;
suuu <- 0;
svvv <- 0;
suvv <- 0;
svuu <- 0;
for (i in 1:N)
{
  ui <- u[i];
  vi <- v[i];
  
  suu <- suu + ui*ui;
  suv <- suv + ui*vi;
  svv <- svv + vi*vi;
  suuu <- suuu + ui*ui*ui;
  svvv <- svvv + vi*vi*vi;
  suvv <- suvv + ui*vi*vi;
  svuu <- svuu + vi*ui*ui;
}

A <- matrix(nrow=2,ncol=2,0);
A[1,1] <- suu;
A[1,2] <- suv;
A[2,1] <- suv;
A[2,2] <- svv;
b <- matrix(nrow=2,ncol=1,0);
b[1,1] <- 0.5*(suuu + suvv);
b[2,1] <- 0.5*(svvv + svuu);

z <- solve(A)%*%b;
uc <- z[1,1];
vc <- z[2,1];
xc <- uc + xbar;
yc <- vc + ybar;

radius <- sqrt(uc*uc + vc*vc + (suu+svv)/N);

print(xc);
print(yc);
print(radius);