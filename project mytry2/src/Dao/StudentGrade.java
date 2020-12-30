package Dao;

import java.sql.*;
import java.util.*;

import Status.stuGrade;
public class StudentGrade {
//添加学生的考试成绩信息
	public void addgrade(stuGrade stugrade) {
		Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "insert into status_grade(id, name, Chinese, Math, English,sumgrade,avegrade) values(?,?,?,?,?,?,?)";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, stugrade.getId());
            stmt.setString(2, stugrade.getName());
            stmt.setInt(3, stugrade.getChinese());
            stmt.setInt(4, stugrade.getMath());
            stmt.setInt(5, stugrade.getEnglish());
            stmt.setInt(6, stugrade.getSumgrade());
            stmt.setInt(7, stugrade.getAvegrade());            
            stmt.executeUpdate();
        }
         catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        System.out.println("添加成功！");
    }
	public List<stuGrade> getAll1() {//在list里面调用
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        List<stuGrade> stuList = new ArrayList<>();

        try {
            conn = MySQLUtils.getConn();
            String sql = "select * from status_grade";
            stmt = conn.createStatement();
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                Integer id = rs.getInt("id");
                String name = rs.getString("name");
                Integer Chinese = rs.getInt("Chinese");
                Integer Math = rs.getInt("Math");
                Integer Engish = rs.getInt("English");               
                stuGrade stugrade = new stuGrade(id, name, Chinese, Math, Engish);
                stuList.add(stugrade);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            MySQLUtils.closeConn(conn, stmt, rs);
        }
        return stuList;
    }
	public stuGrade find(Integer findId) {
        Connection conn = null;
        PreparedStatement stmt = null;
        stuGrade stugrade = null;
        try{
            conn = MySQLUtils.getConn();
            String sql = "select * from status_grade where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, findId);
            ResultSet tmpres = stmt.executeQuery();
            stugrade = new stuGrade();
            while(tmpres.next()){
            	stugrade.setId(tmpres.getInt("id"));
            	stugrade.setName(tmpres.getString("name"));
            	stugrade.setChinese(tmpres.getInt("Chinese"));
            	stugrade.setMath(tmpres.getInt("Math"));
            	stugrade.setEnglish(tmpres.getInt("English"));

            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        return stugrade;
    }
	}
	
	
	
	
	
	
	
	

