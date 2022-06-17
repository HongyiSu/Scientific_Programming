close all;
clear all;
D = importdata("mydata.txt");

x = D(:,1);
phi_0 = D(:,2);
phi_end = D(:,3);

f = gcf;
f.Units = 'centimeters';
f.Position = [0 0 30 30/1.6];
plot(x,phi_0,'--','LineWidth',2);
hold on
plot(x,phi_end,'LineWidth',2);
legend('initial','final');
xlabel("Distance", "FontSize",20);
ylabel("Concentration", "FontSize",20);
hold off
saveas(f,'plot.eps','epsc')

