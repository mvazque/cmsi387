1.File titled ssh_tunnel.png is the evidence

# JD: Most of the desired information was in that screenshot except for the command itself.
#     Fortunately, you came in and asked about it, so I know that you put that command
#     together correctly.

2.The files titled ping_1.png and ping_2.png show the before and after evidence.
 
3.Usage of dU 
 
a) du -d 1 | sort -nrk 1 | head -2 >> cmsi387/homework/io-gymnastics.txt
 
34056	.
15104	./.cache

The first entry is the usage of the home directory and the second is local subdirectory that has the highest disk usage

b) du | grep cmsi387 >> cmsi387/homework/io-gymnastics.txt
480	./cmsi387/homework/Images Hw 2
88	./cmsi387/homework/shell-guide
604	./cmsi387/homework
4	./cmsi387/.git/branches
8	./cmsi387/.git/info
40	./cmsi387/.git/hooks
8	./cmsi387/.git/logs/refs/remotes/origin
12	./cmsi387/.git/logs/refs/remotes
8	./cmsi387/.git/logs/refs/heads
24	./cmsi387/.git/logs/refs
32	./cmsi387/.git/logs
8	./cmsi387/.git/objects/62
64	./cmsi387/.git/objects/f2
8	./cmsi387/.git/objects/fc
8	./cmsi387/.git/objects/2b
8	./cmsi387/.git/objects/d4
8	./cmsi387/.git/objects/18
248	./cmsi387/.git/objects/1a
8	./cmsi387/.git/objects/3e
8	./cmsi387/.git/objects/f8
76	./cmsi387/.git/objects/c2
12	./cmsi387/.git/objects/88
76	./cmsi387/.git/objects/23
8	./cmsi387/.git/objects/2f
8	./cmsi387/.git/objects/ae
8	./cmsi387/.git/objects/be
8	./cmsi387/.git/objects/ff
8	./cmsi387/.git/objects/0e
8	./cmsi387/.git/objects/db
8	./cmsi387/.git/objects/ed
8	./cmsi387/.git/objects/81
8	./cmsi387/.git/objects/d0
8	./cmsi387/.git/objects/ce
8	./cmsi387/.git/objects/cb
12	./cmsi387/.git/objects/59
8	./cmsi387/.git/objects/14
8	./cmsi387/.git/objects/bc
8	./cmsi387/.git/objects/ea
8	./cmsi387/.git/objects/c0
4	./cmsi387/.git/objects/info
8	./cmsi387/.git/objects/4a
8	./cmsi387/.git/objects/43
8	./cmsi387/.git/objects/f6
8	./cmsi387/.git/objects/f4
8	./cmsi387/.git/objects/b6
8	./cmsi387/.git/objects/65
8	./cmsi387/.git/objects/e6
8	./cmsi387/.git/objects/66
8	./cmsi387/.git/objects/b0
248	./cmsi387/.git/objects/74
8	./cmsi387/.git/objects/70
8	./cmsi387/.git/objects/27
8	./cmsi387/.git/objects/b2
8	./cmsi387/.git/objects/6b
8	./cmsi387/.git/objects/36
8	./cmsi387/.git/objects/16
8	./cmsi387/.git/objects/fe
8	./cmsi387/.git/objects/a2
72	./cmsi387/.git/objects/9e
12	./cmsi387/.git/objects/35
8	./cmsi387/.git/objects/56
8	./cmsi387/.git/objects/01
8	./cmsi387/.git/objects/89
248	./cmsi387/.git/objects/5a
12	./cmsi387/.git/objects/8b
8	./cmsi387/.git/objects/0b
4	./cmsi387/.git/objects/pack
12	./cmsi387/.git/objects/9c
8	./cmsi387/.git/objects/ac
8	./cmsi387/.git/objects/ec
8	./cmsi387/.git/objects/2a
8	./cmsi387/.git/objects/e8
392	./cmsi387/.git/objects/24
8	./cmsi387/.git/objects/ee
1880	./cmsi387/.git/objects
12	./cmsi387/.git/refs/remotes/origin
16	./cmsi387/.git/refs/remotes
4	./cmsi387/.git/refs/tags
8	./cmsi387/.git/refs/heads
32	./cmsi387/.git/refs
2032	./cmsi387/.git
2960	./cmsi387
 
4.a) Within ~ directory
ls -i >> inode.txt
9049053 cmis370
9047425 CMSI281
9047387 CMSI284
9047722 cmsi370
9049055 CMSI387
9048959 CMSI387_Repos
9049054 inode.txt
9047271 public_html
9049056 test.txt
9049052 userList.txt
 
b) Within CMSI387 directory
ls -i >> inode.txt
9049054 inode.txt
 
c) Within tmp file
ls -i >> inode.txt
2102619 hsperfdata_aruiz25
1972684 hsperfdata_avreelan
2102620 hsperfdata_cbillin3
1972276 hsperfdata_dondi
1972357 hsperfdata_gleis
1972361 hsperfdata_hdelgadi
1972691 hsperfdata_kgosch
1972686 hsperfdata_kmcgee3
1972688 hsperfdata_kmeilak
1972278 hsperfdata_ksherbin
1972687 hsperfdata_lhunt6
1972432 hsperfdata_mmalefyt
1972360 hsperfdata_mpetredi
1972358 hsperfdata_pdorin
1972277 hsperfdata_slouie4
1972689 hsperfdata_tbramant
1972433 hsperfdata_tvilgaly
1972685 hsperfdata_vkuehn
2102618 hsperfdata_waverill
1972692 inode.txt
1972760 libevent-2.0.21-stable
1972758 libevent-2.0.21-stable.tar.gz
1972759 ncurses-5.9.tar.gz
2102622 ssh-cvJGD29027
2102537 tmux-1261
1972757 tmux-1.8.tar.gz
2102624 update-manager-xM7bH8
 
d)Return from tmp directory
ls -i >> inode.txt
9049053 cmis370
9047425 CMSI281
9047387 CMSI284
9047722 cmsi370
9049055 CMSI387
9048959 CMSI387_Repos
9049054 inode.txt
9047271 public_html
9049056 test.txt
9049052 userList.txt

e) Command to show only the desired file
ls -i | grep inode.txt > inode.txt
9049054 inode.txt
 
5. mount >> io-gymnastics.txt
/dev/sda1 on / type ext4 (rw,errors=remount-ro)
proc on /proc type proc (rw,noexec,nosuid,nodev)
sysfs on /sys type sysfs (rw,noexec,nosuid,nodev)
none on /sys/fs/fuse/connections type fusectl (rw)
none on /sys/kernel/debug type debugfs (rw)
none on /sys/kernel/security type securityfs (rw)
udev on /dev type devtmpfs (rw,mode=0755)
devpts on /dev/pts type devpts (rw,noexec,nosuid,gid=5,mode=0620)
tmpfs on /run type tmpfs (rw,noexec,nosuid,size=10%,mode=0755)
none on /run/lock type tmpfs (rw,noexec,nosuid,nodev,size=5242880)
none on /run/shm type tmpfs (rw,nosuid,nodev)
gvfs-fuse-daemon on /home/miguel/.gvfs type fuse.gvfs-fuse-daemon (rw,nosuid,nodev,user=miguel)
/dev/sdb1 on /media/1BA8-5A64 type vfat (rw,nosuid,nodev,uid=1000,gid=1000,shortname=mixed,dmask=0077,utf8=1,showexec,flush,uhelper=udisks)
/dev/sr1 on /media/U3 System type iso9660 (ro,nosuid,nodev,uid=1000,gid=1000,iocharset=utf8,mode=0400,dmode=0500,uhelper=udisks)
