package Status;
import Dao.stuDao;
import Dao.StuCompreGrade;
import Dao.StudentGrade;

import java.sql.SQLException;
import java.util.*;

public class statusManager {

    Scanner sc = new Scanner(System.in);

    public void Manage(int choice) throws Exception{
        switch (choice){
            case 0:
                list();
                break;
            case  1:
                find();
                break;
            case 2:
                add();
                break;
            case 3:
                change();
                break;
            case 4:
                delete();
                break;
            case 5:
                listgrade();
            	break;
            case 6:
            	addgrade();
            	break;
            case 7:
            	findgrade();
            	break;
            case 8:
            	listcompregrade();
            	break;
            case 9:
            	addcompregrade();
            	break;
            default: {
                throw new Exception("没有该功能，请重新选择！");}
        }
    }
	
	//获取所有学籍信息
    public void list() {
       
        //查找数据库里的数据
        stuDao dao = new stuDao();
        List<StuStatus> list = dao.getAll();
        System.out.println("学生信息列表如下：");
        for(StuStatus stuStatus : list) {
            System.out.println("学号："+stuStatus.getId()+"姓名："+stuStatus.getName()+" 性别："+stuStatus.getSex()+" 家庭住址："+stuStatus.getHomeadress()+"电话号码："+stuStatus.getTelephone());
        }
    }

    //查询学生信息
    public void find() throws SQLException {
        System.out.println("请输入学生学号id：");
        Integer findId = Integer.valueOf(sc.next());
        stuDao dao = new stuDao();
        if(!dao.judgeExist(findId))
            System.out.println("该学生不存在！");
        else{
            StuStatus stuStatus = dao.find(findId);
            System.out.println("学号："+stuStatus.getId()+"姓名："+stuStatus.getName()+" 性别："+stuStatus.getSex()+" 家庭住址："+stuStatus.getHomeadress()+"电话号码："+stuStatus.getTelephone());
        }
    }

    //添加学生信息
    public void add(){
        stuDao dao = new stuDao();
        System.out.println("请输入要添加的学生学号id：");
        Integer addId = Integer.valueOf(sc.next());
        if(dao.judgeExist(addId))
            System.out.println("该学生已存在！");
        else{
            System.out.println("输入姓名：");
            String name = sc.next();
            System.out.println("输入性别：");
            String sex = sc.next();
            System.out.println("输入家庭住址：");
            String homeadress = sc.next();
            System.out.println("输入电话号码：");
            String telephone = sc.next();
            dao.add(new StuStatus(addId,name,sex,homeadress,telephone));
            //System.out.println("查询到如下信息：");
            //list();
        }
    }

    //修改学生信息
    public void change(){
        stuDao dao = new stuDao();
        System.out.println("请输入要修改的学生学号id：");
        Integer changeId = Integer.valueOf(sc.next());
        if(!dao.judgeExist(changeId))
            System.out.println("该学生不存在！");
        else {
            StuStatus stuStatus = dao.find(changeId);
            System.out.println("学号："+stuStatus.getId()+"姓名："+stuStatus.getName()+" 性别："+stuStatus.getSex()+" 家庭住址："+stuStatus.getHomeadress()+"电话号码："+stuStatus.getTelephone());
            System.out.println("请输入需要修改学生的信息（只能选择一项）:");
            System.out.println("1、姓名");
            System.out.println("2、性别");
            System.out.println("3、家庭住址");
            System.out.println("4、电话号码");
            Integer changeChoice = Integer.valueOf(sc.next());
            switch (changeChoice){
                case 1:
                    System.out.println("请输入修改后的姓名：");
                    String name = sc.next();
                    dao.changeName(changeId,name);
                    break;
                case 2:
                    System.out.println("请输入修改后的性别：");
                    String sex = sc.next();
                    dao.changeSex(changeId,sex);
                    break;
                case 3:
                    System.out.println("请输入修改后的家庭住址：");
                    String homeadress = sc.next();
                    dao.changeAcademy(changeId,homeadress);
                    break;
                case 4:
                    System.out.println("请输入修改后的电话号码：");
                    String telephone = sc.next();
                    dao.changeMajor(changeId,telephone);
                    break;
            }
            StuStatus stuStatus1 = dao.find(changeId);//返回修改后的信息
            System.out.println("学号："+stuStatus1.getId()+"姓名："+stuStatus1.getName()+" 性别："+stuStatus1.getSex()+" 家庭住址："+stuStatus1.getHomeadress()+"电话号码："+stuStatus1.getTelephone());
        }
    }
    //删除学生信息
    private void delete() {
        stuDao dao = new stuDao();
        System.out.println("请输入要删除的学生学号id：");
        Integer deleteId = Integer.valueOf(sc.next());
        if(!dao.judgeExist(deleteId))
            System.out.println("该学生不存在！");
        else{
            dao.delete(deleteId);
            list();
        }
    }
    private void listgrade() {
    	int m = 1;
    	StudentGrade studentgrade = new StudentGrade();
        List<stuGrade> list = studentgrade.getAll1();
        Collections.sort(list, new Comparator<stuGrade>(){

			@Override
			public int compare(stuGrade o1, stuGrade o2) {
				if(o1.getSumgrade()-o2.getSumgrade()<0) {
					return 0;
				}else {
					return -1;
				}				
			}        	
        });
        System.out.println("学生成绩信息列表如下(已经按照降序排列)：");
        /*for(stuGrade stugrade : list) {
            System.out.println("学号："+stugrade.getId()+"姓名："+stugrade.getName()+" 语文："+stugrade.getChinese()+" 数学："+stugrade.getMath()+"英语:"+stugrade.getEnglish()+"总成绩: "+stugrade.getSumgrade()+"平均成绩: "+stugrade.getAvegrade());
        }*/
        for(int i = 0 ; i < list.size();i++) {
        	stuGrade stugrade = (stuGrade)list.get(i);
        	stugrade.setRanking(m);
        	System.out.println("学号："+stugrade.getId()+"姓名："+stugrade.getName()+" 语文："+stugrade.getChinese()+" 数学："+stugrade.getMath()+"英语:"+stugrade.getEnglish()+"总成绩: "+stugrade.getSumgrade()+"平均成绩: "+stugrade.getAvegrade()+"名次:"+stugrade.getRanking());
            m++;
        }
        
		
    }
    private void addgrade() {
    	StudentGrade studentgrade = new StudentGrade();
            System.out.println("请输入要添加的学生学号id：");
            Integer id = sc.nextInt();
            System.out.println("输入姓名：");
            String name = sc.next();
            System.out.println("输入语文成绩：");
            Integer Chinese = sc.nextInt();
            System.out.println("输入数学成绩：");
            Integer Math = sc.nextInt();
            System.out.println("输入英语成绩：");
            Integer English = sc.nextInt();           
            studentgrade.addgrade(new stuGrade(id,name,Chinese,Math,English));
            //System.out.println("查询到如下信息：");
            //list();
        }
    private void findgrade()throws SQLException{
    	System.out.println("请输入学生学号id：");
        Integer findId = Integer.valueOf(sc.next());
        StudentGrade studentgrade = new StudentGrade();
            stuGrade stugrade = studentgrade.find(findId);
            System.out.println(" 学号："+stugrade.getId()+" 姓名："+stugrade.getName()+" 语文："+stugrade.getChinese()+" 数学："+stugrade.getMath()+" 英语："+stugrade.getEnglish()+" 总成绩: "+stugrade.getSumgrade()+" 平均成绩: "+stugrade.getAvegrade());
        }
    private void listcompregrade() {
    	int j = 1;
    	StuCompreGrade stucompregrade = new StuCompreGrade();
        List<CompreGrade> list = stucompregrade.getAll2();
        System.out.println("学生综合成绩信息列表(已经按照降序排列)：");
        Collections.sort(list, new Comparator<CompreGrade>(){

			@Override
			public int compare(CompreGrade o1, CompreGrade o2) {
				if(o1.getComprescore()-o2.getComprescore()<0) {
					return 0;
				}else {
					return -1;
				}				
			}        	
        });
        /*for(CompreGrade compregrade : list) {
            System.out.println("学号："+compregrade.getId()+"姓名："+compregrade.getName()+" 总成绩："+compregrade.getTotalscore()+" 同学评分："+compregrade.getMatescore()+"老师评分:"+compregrade.getTeacherscore()+"综合评分: "+compregrade.getComprescore());
        }*/
        for(int i = 0 ; i < list.size();i++) {
        	CompreGrade compregrade = (CompreGrade)list.get(i);
        	compregrade.setCompreranking(j);
        	System.out.println(" 学号："+compregrade.getId()+" 姓名："+compregrade.getName()+" 总成绩："+compregrade.getTotalscore()+" 同学评分："+compregrade.getMatescore()+"老师评分: "+compregrade.getTeacherscore()+" 综合评分: "+compregrade.getComprescore()+" 综合名次: " + compregrade.getCompreranking());
            j++;
        }
	}
    private void addcompregrade() {
    	StuCompreGrade stucompregrade = new StuCompreGrade();
        System.out.println("请输入要添加的学生学号id：");
        Integer id = sc.nextInt();
        System.out.println("输入姓名：");
        String name = sc.next();
        System.out.println("输入总成绩：");
        Integer totalscore = sc.nextInt();
        System.out.println("输入同学评分：");
        Integer matescore = sc.nextInt();
        System.out.println("输入老师评分：");
        Integer teacherscore = sc.nextInt();           
        stucompregrade.addcompregrade(new CompreGrade(id, name, totalscore, matescore, teacherscore));
		
	}    
    }


