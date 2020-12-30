package Dao;
import java.sql.*;
import java.util.*;
import Status.CompreGrade;



public class StuCompreGrade {

	public void addcompregrade(CompreGrade compregrade) {
		Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "insert into status_compregrade(id, name, totalscore, matescore,teacherscore,comprescore) values(?,?,?,?,?,?)";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, compregrade.getId());
            stmt.setString(2, compregrade.getName());
            stmt.setInt(3, compregrade.getTotalscore());
            stmt.setInt(4, compregrade.getMatescore());
            stmt.setInt(5, compregrade.getTeacherscore());
            stmt.setDouble(6, compregrade.getComprescore());           
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
	public List<CompreGrade> getAll2() {//在list里面调用
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        List<CompreGrade> stuList = new ArrayList<>();

        try {
            conn = MySQLUtils.getConn();
            String sql = "select * from status_compregrade";
            stmt = conn.createStatement();
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                Integer id = rs.getInt("id");
                String name = rs.getString("name");
                Integer totalscore = rs.getInt("totalscore");
                Integer matescore = rs.getInt("matescore");
                Integer teacherscore = rs.getInt("teacherscore");               
                CompreGrade compregrade = new CompreGrade(id, name, totalscore, matescore, teacherscore);
                stuList.add(compregrade);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            MySQLUtils.closeConn(conn, stmt, rs);
        }
        return stuList;
    }
	
	
	
}
