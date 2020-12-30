package Status;
import java.util.Scanner;

public class statusMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        statusManager statusManager = new statusManager();
        boolean flag = true;

        while (flag) {
            //界面
            System.out.println("------------");
            System.out.println("欢迎来到学生综合测评系统");
            System.out.println("0 显示全部学籍信息");
            System.out.println("1 按学号搜索学生信息");
            System.out.println("2 增加学生信息");
            System.out.println("3 修改学生信息");
            System.out.println("4 删除学生信息");
            System.out.println("5 列出学生的考试成绩表");
            System.out.println("6 添加学生考试成绩信息");
            System.out.println("7 按学号查询学生考试成绩信息");
            System.out.println("8 显示学生的综合测评表 ");
            System.out.println("9 添加学生的综合成绩 ");
            System.out.println("10 退出 ");            
            System.out.println("------------");
            System.out.println("请选择：");

            int choice = sc.nextInt();
            //   try/catch
            try {
                if (choice == 10) {
                    System.out.println("您已退出该系统");
                    return;
                } else
                    statusManager.Manage(choice);

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        sc.close();
    }
}

