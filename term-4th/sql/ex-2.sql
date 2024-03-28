create database QUANLYKHOAHOC
go
use QUANLYKHOAHOC
go
create table BaiBao
(
	IDBaiBao char(10),
	IDTruong char(10),
	TenBaiBao nvarchar(50),
	IDPhanBien char(10)
	primary key (IDBaiBao, IDTruong)
)
go
create table NhaKhoaHoc
(
	IDNhaKhoaHoc char(10),
	IDTruong char(10),
	HoTen nvarchar(50),
	NgaySinh datetime
	primary key (IDNhaKhoaHoc, IDTruong)
)
go
create table THAMGIA
(
	IDBaiBao char(10),
	IDTruong char(10),
	IDNhaKhoaHoc char(10),
	ThanhTich nvarchar(50)
	primary key (IDBaiBao, IDNhaKhoaHoc, IDTruong)
)
go
alter table BaiBao
add
	constraint FK_BaiBao_NhaKhoaHoc
	foreign key (IDPhanBien, IDTruong)
	references NhaKhoaHoc(IDNhaKhoaHoc, IDTruong)
go
alter table THAMGIA
add
	constraint FK_THAMGIA_BaiBao
	foreign key (IDBaiBao, IDTruong)
	references BaiBao(IDBaiBao, IDTruong)
go
alter table THAMGIA
add
	constraint FK_THAMGIA_NhaKhoaHoc
	foreign key (IDNhaKhoaHoc, IDTruong)
	references NhaKhoaHoc(IDNhaKhoaHoc, IDTruong)
go
insert into NhaKhoaHoc(IDNhaKhoaHoc, IDTruong, HoTen, NgaySinh) values ('N2', 'TN', N'Nguyễn', '7/15/1984')
insert into NhaKhoaHoc(IDNhaKhoaHoc, IDTruong, HoTen, NgaySinh) values ('N2', 'BK', N'Tín', '9/26/1983')
insert into NhaKhoaHoc(IDNhaKhoaHoc, IDTruong, HoTen, NgaySinh) values ('N1', 'BK', N'Hà', '10/18/1984')
insert into NhaKhoaHoc(IDNhaKhoaHoc, IDTruong, HoTen, NgaySinh) values ('N1', 'TN', N'Hữu', '12/9/1984')
insert into NhaKhoaHoc(IDNhaKhoaHoc, IDTruong, HoTen, NgaySinh) values ('N3', 'BK', N'Nhân', '12/1/1982')
insert into BaiBao(IDBaiBao, IDTruong, TenBaiBao, IDPhanBien) values ('B1', 'TN', N'Phát Triển TPTM', 'N2')
insert into BaiBao(IDBaiBao, IDTruong, TenBaiBao, IDPhanBien) values ('B1', 'BK', N'Nghiên cứu BI', 'N2')
insert into BaiBao(IDBaiBao, IDTruong, TenBaiBao, IDPhanBien) values ('B2', 'BK', N'Xử lý ngôn ngữ', 'N2')
insert into THAMGIA(IDBaiBao, IDTruong, IDNhaKhoaHoc, ThanhTich) values('B1', 'TN', 'N1', N'Giỏi')
insert into THAMGIA(IDBaiBao, IDTruong, IDNhaKhoaHoc, ThanhTich) values('B1', 'BK', 'N1', N'Xuất sắc')
insert into THAMGIA(IDBaiBao, IDTruong, IDNhaKhoaHoc, ThanhTich) values('B1', 'BK', 'N3', N'Khá')
insert into THAMGIA(IDBaiBao, IDTruong, IDNhaKhoaHoc, ThanhTich) values('B2', 'BK', 'N1', N'Trung bình')
insert into THAMGIA(IDBaiBao, IDTruong, IDNhaKhoaHoc, ThanhTich) values('B2', 'BK', 'N3', N'Khá')