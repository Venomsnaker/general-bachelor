create database QLGVABC
go
use QLGVABC
go
create table GiaoVien
(
	MaGV char(4),
	TenGV nvarchar(60),
	NgaySinh datetime,
	bmGV char(4),
	primary key (MaGV)
)
go
create table BoMon
(
	MaBM char(4),
	TenBM nvarchar(60),
	primary key (MaBM)
)
go
alter table GiaoVien add foreign key (bmGV) references BoMon (MaBM)
go
insert into GiaoVien values('GV01', N'Bùi Quốc Huy', '12/31/2004', NULL)
insert into GiaoVien(TenGV, NgaySinh, MaGV, bmGV) values(N'Nguyễn Tuân Công', '4/23/2004', 'GV02', NULL)
insert into GiaoVien values('GV03', N'Văn Tuấn Kiệt', '4/5/2004', NULL)
insert into BoMon values ('BM01', N'Hệ Thống Thông Tin')
insert into BoMon values ('BM02', N'Công nghệ phần mềm')
Update GiaoVien set bmGV = 'BM01' where MaGV = 'GV01'
Update GiaoVien set bmGV = 'BM02' where MaGV = 'GV02'
Update GiaoVien set bmGV = 'BM02' where MaGV = 'GV03'
