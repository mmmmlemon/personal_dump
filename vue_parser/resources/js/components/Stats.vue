<template>
    <div class="container">
        <h4>{{steamuser.user_info.personaname }} stats</h4>

            <div class="row">
                <div class="col-md-4">
                    <img :src="steamuser.user_info.avatarfull" alt="">
                </div>
                <div class="col-md-8">
                    <table class="table table-striped">
                        <tr>
                            <th>Steam ID</th>
                            <th>Profile created at</th>
                            <th>Last online</th>
                            <th>Games owned total</th>   
                        </tr>
                        <tr>
                            <td>{{steamuser.user_info.steamid}}</td>
                            <td>{{steamuser.user_info.timecreated}}</td>
                            <td>{{steamuser.user_info.lastlogoff}}</td>
                            <td>{{steamuser.user_games_count}}</td>
                        </tr>
                    </table>
                </div>
            </div>

      

    </div>
</template>

<script>
export default {
    data(){
        return{
            steamuser: {
                user_info: {
                    personaname: "",
                    avatarfull: ""
                }
            }
        }
    },
     created() {
        let uri = `/api/steamuser/stats/${this.$route.params.id}`;
        this.axios.get(uri).then((response) => {
            this.steamuser = response.data;
        })
    }
}
</script>