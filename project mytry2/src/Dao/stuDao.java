package Dao;


import java.sql.*;
import java.util.*;

import Status.StuStatus;

public class stuDao {

    //添加学生信息
    public void add(StuStatus stuStatus){
        //需要连接数据库，使用sql语句进行添加
        Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "insert into status_info(id, name, sex, homeadress, telephone) values(?,?,?,?,?)";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, stuStatus.getId());
            stmt.setString(2, stuStatus.getName());
            stmt.setString(3, stuStatus.getSex());
            stmt.setString(4, stuStatus.getHomeadress());
            stmt.setString(5, stuStatus.getTelephone());
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

        /**修改学生信息
    连接数据库，foreach进行sql语句替换*/
    //修改学生姓名
    public void changeName(Integer changeId,String name) {
        Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "update status_info set name = ? where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, name);
            stmt.setInt(2, changeId);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        System.out.println("姓名修改成功!!");
    }
    //修改学生性别
    public void changeSex(Integer changeId,String sex) {
        Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "update status_info set sex = ? where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, sex);
            stmt.setInt(2, changeId);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        System.out.println("性别修改成功!!");
    }
    //修改学生学院
    public void changeAcademy(Integer changeId, String homeadress) {
        Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "update status_info set homeadress = ? where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, homeadress);
            stmt.setInt(2, changeId);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        System.out.println("家庭住址修改成功!!");
    }
    //修改学生专业
    public void changeMajor(Integer changeId, String telephone) {
        Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "update status_info set telephone = ? where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, telephone);
            stmt.setInt(2, changeId);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        System.out.println("电话号码修改成功!!");
    }
    //删除学生信息
    public void delete(Integer deleteId) {
        //连接数据库，sql语句删除
        Connection conn = null;
        PreparedStatement stmt = null;
        try {
            conn = MySQLUtils.getConn();
            String sql = "delete from status_info where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, deleteId);
            stmt.executeUpdate();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        System.out.println("删除成功!!");
    }

//数据库操作
    public List<StuStatus> getAll() {//在list里面调用
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        List<StuStatus> stuList = new ArrayList<>();

        try {
            conn = MySQLUtils.getConn();
            String sql = "select * from status_info";
            stmt = conn.createStatement();
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                Integer id = rs.getInt("id");
                String name = rs.getString("name");
                String sex = rs.getString("sex");
                String homeadress = rs.getString("homeadress");
                String telephone = rs.getString("telephone");
                StuStatus stuStatus = new StuStatus(id, name, sex, homeadress, telephone);

                stuList.add(stuStatus);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            MySQLUtils.closeConn(conn, stmt, rs);
        }
        return stuList;
    }

    //判断id是否存在
    public boolean judgeExist(Integer stuId){
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        int count = 0;
        try {
            conn = MySQLUtils.getConn();
            String sql = "select count(*) as count from status_info where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, stuId);
            rs = stmt.executeQuery();
            while(rs.next()){
                count = rs.getInt("count");
            }
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt, rs);
        }
        if(count==0) return false;
        else
            return true;
    }


    //数据库查找
    public StuStatus find(Integer findId) {
        Connection conn = null;
        PreparedStatement stmt = null;
        StuStatus stuStatus = null;
        try{
            conn = MySQLUtils.getConn();
            String sql = "select * from status_info where id = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setInt(1, findId);
            ResultSet tmpres = stmt.executeQuery();
            stuStatus = new StuStatus();
            while(tmpres.next()){
                stuStatus.setId(tmpres.getInt("id"));
                stuStatus.setName(tmpres.getString("name"));
                stuStatus.setSex(tmpres.getString("sex"));
                stuStatus.setHomeadress(tmpres.getString("homeadress"));
                stuStatus.setTelephone(tmpres.getString("telephone"));  
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
        finally{
            MySQLUtils.closeConn(conn, stmt);
        }
        return stuStatus;
    }


}
