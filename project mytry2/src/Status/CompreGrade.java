package Status;

public class CompreGrade {
     private int id;
     private String name ;
     private int totalscore;
     private int matescore;
     private int teacherscore;
     private float comprescore;
     private int compreranking;	
	public CompreGrade(int id, String name, int totalscore, int matescore, int teacherscore) {
		super();
		this.id = id;
		this.name = name;
		this.totalscore = totalscore;
		this.matescore = matescore;
		this.teacherscore = teacherscore;
		this.comprescore = (float) (totalscore * 0.6 + matescore * 0.1 + teacherscore * 0.3);
	}
	public CompreGrade() {
		super();
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getTotalscore() {
		return totalscore;
	}
	public void setTotalscore(int totalscore) {
		this.totalscore = totalscore;
	}
	public int getMatescore() {
		return matescore;
	}
	public void setMatescore(int matescore) {
		this.matescore = matescore;
	}
	public int getTeacherscore() {
		return teacherscore;
	}
	public void setTeacherscore(int teacherscore) {
		this.teacherscore = teacherscore;
	}
	public float getComprescore() {
		return (float) (totalscore * 0.6 + matescore * 0.1 + teacherscore * 0.3);
	}
	public int getCompreranking() {
		return compreranking;
	}
	public void setCompreranking(int compreranking) {
		this.compreranking = compreranking;
	}     
}
