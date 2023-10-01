syms x

disp("Cau 1 - a")

disp("Gioi han cua (e^(2*x) - 1) / x tai 0 la:")
disp(limit( ((exp(2*x) - 1) / x), x, 0 ))

disp("Gioi han cua ln(x) / x tai vo cuc la:")
disp(limit( (log(x) /x), x, inf ))

disp("Gioi han cua arcsin(x) / x tai 0 la:")
disp(limit( (asin(x) /x) , x, 0))

disp("Cau 1 - b")

disp("Dao ham bac 1 cua x^2 * sin(2x):")
disp(diff( x^2 * sin(2*x) ))

disp("Gia tri dao ham bac 1 cua e^(x/10) tai 3 la:")
f = diff( exp(x/10));
disp(subs(f, x, 3))

disp("Cau 1 - c")

disp("Gia tri cua tich phan y*e^-3y*dy tu 2 den vo cuc la:")
disp(int((x*exp(-3*x)), 2, inf))

disp("Gia tri cua tich phan dx / sqrt(1-x^2) tu 0 den 1 la:")
disp(int((1/(sqrt(1-x^2))), 0, 1 ))

disp("Cau 2")
disp("L1 = Gioi han cua f(x) = x^2 khi x tien den 1^- la:")
l1 = limit( x^2, x, 1, 'left');
disp(l1)
disp("L2 = Gioi han cua f(x) = sqrt(x) khi x tien den 1^+ la:")
l2 = limit( sqrt(x), x, 1, 'right');
disp(l2)
disp("Gia tri cua f(1) la:")
res1 = subs(sqrt(x), x, 1);
disp(res1)

if ((l1 == l2) && (l2 == res1))
    disp("Vi L1 = L2 = f(1) nen ham so lien tuc tai 1");
else
    disp("Vi mot trong cac dieu kien khong thoa nen ham so khong lien tuc tai 1");
end

disp("Cau 3")

f = (x^2 * sin(1/x) - 0)/ (x - 0);
disp("Gioi han cua (x^2 * sin(1/x) - 0) / (x - 0) khi x tien den 0^+ la:")
l3 = limit(f, x, 0, 'right');
disp(l3)
if (l3 == 0)
    disp("Ham so co dao ham tai cac diem khi tien gan den 0^+.")
else
    disp("Ham so khong co dao ham tai cac diem khi tien gan den 0^+.")
end

disp("Gioi han cua (x^2 * sin(1/x) - 0) / (x - 0) khi x tien den 0^- la:")
l4 = limit(f, x, 0, 'left');
disp(l4)
if (l4 == 0)
    disp("Ham so co dao ham tai cac diem khi tien gan den 0^-.")
else
    disp("Ham so khong co dao ham tai cac diem khi tien gan den 0^-.")
end

derivative = diff(x* x * sin(1/x));
disp("Dao ham cua x^2 * sin(1/x) la:")
disp(derivative)

disp("Gia tri dao ham cua x^2 * sin(1/x) khi tien den 0^+ la:")
d3 = limit(derivative, x, 0, 'right');
disp(d3)

disp("Gia tri dao ham cua x^2 * sin(1/x) khi tien den 0^- la:")
d4 = limit(derivative, x, 0, 'left');
disp(d4)

disp("f'(0) = 0 (theo de bai)")

if ((d3 == 0) && (d4 == 0))
    disp("Do cac dieu kien thoa nen gam so co dao ham tai diem x = 0")
else
    disp("Cac dieu kien khong thoa nen ham so khong co dao ham tai diem x = 0")
end

disp("")
