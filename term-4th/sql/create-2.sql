create database QLPhuong
go
use QLPhuong
go
create table Phuong
(
	IDPhuong char(4),
	IDChuTich char(4),
	TenPhuong nvarchar(20)
	primary key (IDPhuong)
)
go
create table KhuPho
(
	IDKhuPho int,
	IDTrKhuPho char(4),
	IDPhuong char(4)
	primary key (IDKhuPho, IDPhuong)
)
go
create table Dan
(
	IDDan char(4),
	IDKhuPho int,
	Ten nvarchar(20),
	TinhTrang nvarchar(50),
	IDPhuong char(4)
	primary key (IDDan, IDPhuong)
)
go
alter table Phuong
add
	constraint FK_Phuong_Dan
	foreign key (IDChuTich, IDPhuong)
	references Dan(IDDan, IDPhuong)
go
alter table KhuPho
add
	constraint FK_KhuPho_Phuong
	foreign key (IDPhuong)
	references Phuong(IDPhuong)
go
alter table KhuPho
add
	constraint FK_KhuPho_Dan
	foreign key (IDTrKhuPho, IDPhuong)
	references Dan(IDDan, IDPhuong)
go
alter table Dan
add
	constraint FK_Dan_Phuong
	foreign key (IDPhuong)
	references Phuong(IDPhuong)
go
alter table Dan
add
	constraint FK_Dan_KhuPho
	foreign key (IDKhuPho, IDPhuong)
	references KhuPho(IDKhuPho, IDPhuong)
go
insert into Phuong values('PHA', NULL, N'Phường A')
insert into Phuong values('PHB', NULL, N'Phường B')
insert into KhuPho(IDPhuong, IDTrKhuPho, IDKhuPho) values ('PHA', NULL, 1)
insert into KhuPho(IDPhuong, IDTrKhuPho, IDKhuPho) values ('PHB', NULL, 2)
insert into Dan(IDPhuong, IDKhuPho, Ten, TinhTrang, IDDan) values('PHA', 1, N'Bùi Quốc Huy', N'còn sống', 'NVA')
insert into Dan(IDPhuong, IDKhuPho, Ten, TinhTrang, IDDan) values('PHB', 2, N'Lâm Quốc Huy', N'đã chết', 'NVB')
update Phuong set IDChuTich = 'NVA'
where IDPhuong = 'PHA'
update KhuPho set IDTrKhuPho = 'NVA'
where IDKhuPho = 1 and IDPhuong = 'PHA'