<template>
  <div class="row justify-content-center">
      <div class="col-md-8">
       <div class="container">
            <div style="margin: 10px;">
                <button class="btn btn-success">
                   <router-link to="/createUser" style="color: white;">Add new Steam User</router-link>
                </button> 
            </div>
            <div>
                <table class="table table-hover">
                    <thead>
                        <tr>
                            <th>Database ID</th>
                            <th>Steam username</th>
                            <th>Steam ID</th>
                            <th></th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr v-for="user in steamusers" :key="user.id">
                            <td>{{ user.id }}</td>
                            <td><h3><router-link :to="{name: 'stats', params: { id: user.id }}">{{user.username}}</router-link></h3></td>
                            <td>{{user.steam_id}}</td>
                            <td>  <router-link :to="{name: 'editUser', params: { id: user.id }}" class="btn btn-primary">Edit</router-link>
                            <button class="btn btn-danger" @click="deleteUser(user.id)">Delete</button></td>
                        </tr>
                    </tbody>
                </table>
            </div>
       </div>
      </div>
  </div>
</template>

<script>
export default {
    data(){
        return{
            steamusers: {}
        }
    },
    mounted(){
         this.$parent.currentPage = "users";
    },
    created(){
        let uri = '/api/steamusers';
        this.axios.get(uri).then(response => {
            this.steamusers = response.data.data;
        })
    },
    methods: {
        deleteUser(id)
        {
            let uri = `/api/steamuser/delete/${id}`;
            this.axios.delete(uri).then(response => {
                this.steamusers.splice(this.steamusers.indexOf(id), 1);
            });
        }
    }
}
</script>