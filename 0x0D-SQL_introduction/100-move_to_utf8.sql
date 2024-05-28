-- script that converts hbtn_0c_0 database to UTF8
Use `hbtn_0c_0`
ALTER TABLE `first_table`
CONVERT TO CHARACTER SET utf8mb4 COLLATE utf8mb_unicode_ci;
