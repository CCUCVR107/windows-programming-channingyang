function work2(img1)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
im1=img1;
[m,n]=size(im1);
h=imhist(im1);
f1 = im2uint8(ones(m,n));
PDF=h/numel(im1);
CDF=cumsum(PDF);
j=CDF.*256;
cc=round(j);
for i=1:256

    nn = find(cc==i);

    L = length(nn);

    for k=1:L

    nn1 = find(im1==(nn(k)-1));

    f1(nn1)=i;             

    end

end
imshow(f1),figure,imhist(im1),figure,imhist(f1);

end

